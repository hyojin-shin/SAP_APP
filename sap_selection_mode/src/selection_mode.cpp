/***************************************************************
Program : selection_node
File : selection_mode.cpp
Function : Subscriber
Description : 선택 모드
Author : SAP Possible
Environment : Ubuntu 16.04 / ROS kinetic
Revisions : 1.0.0 21/11/10 First release
***************************************************************/

#include <iostream>
#include <ros/ros.h>  // ROS 기본헤더파일
#include <mysql/mysql.h>
#include <string>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <unistd.h>
#include <algorithm>
#include "std_msgs/String.h"
#include "sap_selection_mode/Msg.h" // Msg메시지파일헤더(빌드후자동생성됨)
#include "sap_selection_mode/mode_msg.h" // mode_msg메시지파일헤더(빌드후자동생성됨)
using namespace std;

MYSQL *connection = NULL;
MYSQL_RES *result = NULL;
MYSQL_ROW row;



// 모의 환경에서 사용하는 좌표 정보

//map
double xzone0 = 0.3571;
double yzone0 = 0.6685;
double xzone1 = 0.3389;
double yzone1 = -0.5712;
double xzone2 = -0.4176;
double yzone2 = 0.6699;
double xzone3 = -0.4133;
double yzone3 = -0.6079;



// 함수 선언
bool moveToGoal(double xGoal, double yGoal);

// 목적지 도착 성공여부
bool goalReached = false;



// 사용자 선택 위한 클래스
class Choice {
	public:
		Choice();
		~Choice();
		int mode = 0;
		int zone = 0;
		void getMode();

};

// Constructor
Choice::Choice(){
	////////////////////////////////////database////////////////////////////////////
	connection = mysql_init(connection);
	mysql_real_connect(connection, "ip", "id", "passwd", "test", port, NULL, 0);
	if (mysql_query(connection, "SELECT * FROM APP_table")) {
		ROS_INFO("Query Error: %s", mysql_error(connection));
		exit(1);
	}
	else {
		result = mysql_use_result(connection);
		for (int i = 0; i < mysql_field_count(connection); ++i) {
			std::stringstream ss;
			row = mysql_fetch_row(result);
			if (row <= 0) {
				break;
			}
			for (int j = 0; j < mysql_num_fields(result); ++j) {
				ss << row[j] << " ";
			}
			ROS_INFO("%s", ss.str().c_str());
		}
		mysql_free_result(result);
	}
	////////////////////////////////////////////////////////////////////////////////
}

// Destructor
Choice::~Choice() {}

// 현재 선택된 모드를 반환하는 함수이다
void Choice::getMode(){
	/////////////////////////////////database select////////////////////////////////
	string query = "SELECT mode,zone FROM APP_table ORDER BY id DESC LIMIT 1";
	if (mysql_query(connection, query.c_str())) {
		ROS_INFO("Query Error: %s", mysql_error(connection));
		exit(1);
	}
	else {
		result = mysql_use_result(connection);
		for (int i = 0; i < mysql_field_count(connection); ++i) {
			std::stringstream ss;
			row = mysql_fetch_row(result);
			if (row <= 0) {
				break;
			}
			
			ROS_INFO("%s", ss.str().c_str());
			
			mode = stoi(row[0]);
			zone = stoi(row[1]);
		}
		
	}

	cout << "mode: " << mode << '\n';
	cout << "zone: " << zone << '\n';

	//////////////////////////////////////////////////////////////////////////////// 	
}


int main(int argc, char** argv) { // 노드 메인 함수
	ros::init(argc, argv, "selection_node"); // 노드명 선언
	ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드핸들 선언

	Choice choice;

	while (true) {
		ros::spinOnce();
		// 사용자로부터 모드 선택을 받는다
		ros::Duration(1).sleep();
		choice.getMode(); // 현재 선택된 모드를 mode에 저장
		ROS_INFO("mode= %d", choice.mode); // 현재 선택된 모드를 표시한다
		ROS_INFO("zone= %d", choice.zone); // 현재 선택된 모드를 표시한다

		if (choice.mode == 1) {
			ROS_INFO("mode fin");
			
			if (choice.zone == 0) { // 0번 구역으로 이동
				goalReached = moveToGoal(xzone0, yzone0);
			}
			else if (choice.zone == 1) { // 1번 구역으로 이동
				goalReached = moveToGoal(xzone1, yzone1);
			}
			else if (choice.zone == 2) { // 2번 구역으로 이동
				goalReached = moveToGoal(xzone2, yzone2);
			}
			else if (choice.zone == 3) { // 3번 구역으로 이동
				goalReached = moveToGoal(xzone3, yzone3);
			}

			if (goalReached) { // 선택된 구역에 도착했으면 Congratulations! 출력
				ROS_INFO("Congratulations!");
				ROS_INFO("~Purifying~");
				ros::spinOnce();
			}
			else { // 정확한 주행 실패 시 Hard Luck! 출력
				ROS_INFO("Hard Luck!");
			}
			
		}
	}

	return 0;
}

// 특정 구역 1개로 주행하는 함수이다
// 파라미터: 선택된 구역 좌표
bool moveToGoal(double xGoal, double yGoal) {
	// define a client for to send goal requests to the move_base server through a SimpleActionClient
	actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);
	// wait for the action server to come up
	while (!ac.waitForServer(ros::Duration(5.0))) {
		ROS_INFO("Waiting for the move_base action server to come up");
	}
	move_base_msgs::MoveBaseGoal goal;
	// set up the frame parameters
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();
	// 선택된 구역로 주행
	goal.target_pose.pose.position.x = xGoal;
	goal.target_pose.pose.position.y = yGoal;
	goal.target_pose.pose.position.z = 0.0;
	goal.target_pose.pose.orientation.x = 0.0;
	goal.target_pose.pose.orientation.y = 0.0;
	goal.target_pose.pose.orientation.z = 0.0;
	goal.target_pose.pose.orientation.w = 1.0;
	ROS_INFO("Sending goal location ...");
	ac.sendGoal(goal);
	ac.waitForResult();
	if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) { // 선택된 구역에 성공적으로 도착했을 경우
		ROS_INFO("You have reached the destination");
		return true;
	}
	else { // 선택된 구역에 도착을 실패했을 경우
		ROS_INFO("The robot failed to reach the destination");
		return false;
	}
}
