#include "ros/ros.h"// ROS 기본 헤더 파일
#include "sap_mode_one/mode_msg.h" // mode_msg메시지파일헤더(빌드후자동생성됨)

//사용자가 모드를 선택하는 함수이다.
char choose(){
    char choice='q';
    std::cout<<"|-------------------------------|"<<std::endl;
    std::cout<<"|원하는 모드를 선택하세요."<<std::endl;
    std::cout<<"| Mode 1: 사용자 설정 스팟 이동 모드 "<<std::endl;
    std::cout<<"| Mode 2: 전체스팟 데이터 측정 모드 "<<std::endl;
    std::cout<<"| Mode 3: 최고 미세먼지 구역 이동 모드 "<<std::endl;
    std::cout<<"| Mode 4: 미세먼지 수치에 따른 자율주행 모드 "<<std::endl;
    std::cout<<"| Mode 5: 순차적 자율주행 모드 "<<std::endl;
    std::cout<<"|'0': 정지"<<std::endl;
    std::cout<<"|'q': 종료 "<<std::endl;
    std::cout<<"|-------------------------------|"<<std::endl;
    std::cout<<"|WHICH MODE?"<<std::endl;
    std::cin>>choice;
    return choice;
}


int main(int argc, char **argv) // 노드 메인 함수
{
    ros::init(argc, argv, "mode_publisher"); // 노드명 초기화
    ros::NodeHandle n;// ROS 시스템과 통신을 위한 노드 핸들 선언

    ros::Publisher mode_pub= n.advertise<sap_mode_one::mode_msg>("mode_msg", 100);
    // 루프주기를설정한다. "10" 이라는것은10Hz를말하는것으로0.1초간격으로반복된다
    ros::Rate loop_rate(10);
    // mode_msg메시지파일형식으로msg라는메시지를선언
    sap_mode_one::mode_msg msg;

    // 메시지에사용될변수선언
    int count = 0;
    char choice='q';

    do{
        choice=choose();

        int n = choice - '0'; //int형으로 형변환
        msg.data=n;    // choice라는 변수값을 msg의 하위 data 메시지에 담는다
        if(choice=='1'){	//Mode 1 실행
            mode_pub.publish(msg);// 메시지를발행한다
	
        }
        else if(choice=='2'){	//Mode 2 실행
            mode_pub.publish(msg);// 메시지를발행한다
	
        }
        else if(choice=='3'){	//Mode 3 실행
            mode_pub.publish(msg);// 메시지를발행한다
	  
        }
        else if(choice=='4'){	//Mode 4 실행
            mode_pub.publish(msg);// 메시지를발행한다
	  
        }
        else if(choice=='5'){	//Mode 5 실행
            mode_pub.publish(msg);// 메시지를발행한다
	
	}
	else if(choice=='0'){
	    mode_pub.publish(msg);	
	}

    }while(choice !='q');


    /*while (ros::ok())
    {
        msg.stamp= ros::Time::now();// 현재시간을msg의하위stamp 메시지에담는다
        msg.data= count; // count라는변수값을msg의하위data 메시지에담는다
        ROS_INFO("send msg= %d", msg.stamp.sec); // stamp.sec메시지를표시한다
        ROS_INFO("send msg= %d", msg.stamp.nsec); // stamp.nsec메시지를표시한다
        ROS_INFO("send msg= %d", msg.data); // data 메시지를표시한다
        ros_tutorial_pub.publish(msg);// 메시지를발행한다
        loop_rate.sleep();// 위에서정한루프주기에따라슬립에들어간다
        ++count;// count 변수1씩증가
    }*/

    return 0;
}
