# SAP_APP
Smart Autonomous moving air Purifier APP

## 목차
- [소개](#소개)
- [개발도구](#개발도구)
- [화면구성](#화면구성)
- [앱시나리오](#앱시나리오)
- [모드시나리오](#모드시나리오)
- [해당논문](#해당논문)
- [REFERENCE](#REFERENCE)
***
## 소개
스마트 자율주행 공기청정기 로봇 동작 앱<br>
- 앱을 통해 간편히 로봇을 모드 변경할 수 있고, 원하는 구역으로 이동시킬 수 있습니다.


- 이전에 개발한 스마트 자율주행 공기청정기([seonghee-lee/Capstone](https://github.com/seonghee-lee/Capstone))에서
 모드와 앱을 추가 개발하였습니다.
<br><br>
## 개발도구
앱: <img src="https://img.shields.io/badge/Android-3DDC84?style=flat-square&logo=Android&logoColor=white"/> 
<img src="https://img.shields.io/badge/Java-007396?style=flat-square&logo=Java&logoColor=white"/> 
<img src="https://img.shields.io/badge/Apache-D22128?style=flat-square&logo=Apache&logoColor=black"/> 
<img src="https://img.shields.io/badge/PHP-777BB4?style=flat-square&logo=PHP&logoColor=black"/> 
<img src="https://img.shields.io/badge/XAMPP-FB7A24?style=flat-square&logo=XAMPP&logoColor=black"/> <br>
로봇: <img src="https://img.shields.io/badge/Ubuntu-E95420?style=flat-square&logo=Ubuntu&logoColor=black"/> 
<img src="https://img.shields.io/badge/-Raspberry Pi-A22846?style=flat-square&logo=Raspberry Pi&logoColor=white"/> 
<img src="https://img.shields.io/badge/-C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/> 
<img src="https://img.shields.io/badge/MySQL-4479A1?style=flat-square&logo=MySQL&logoColor=black"/>
<br><br>
## 화면구성
<center><img src = "https://user-images.githubusercontent.com/76603536/168049074-9d571f34-1802-4c5e-9a38-5bde2f033a7f.png" width="80%" ></center>
<br>

## 앱시나리오
1. 앱을 실행시키면 모드 선택 화면이 보인다.<br><br>
2. 실행시킬 모드를 선택한다.<br><br>
3. 각 해당 모드의 값(Selection mode=1, Autonomous highest zone mode=2, Autonomous instant purification mode=3)이 로봇DB에 저장된다.<br>
  3-1. Selection mode 선택시 구역(zone) 선택화면으로 이동한다.<br>
  3-2. 구역 값(ZONE0=0, ZONE1=1, ZONE2=2, ZONE3=3)이 로봇DB에 저장된다.<br><br>
4. 로봇은 전원이 ON되면 DB에서 모드 및 구역 값을 먼저 읽고 해당 모드를 동작함.<br><br>
5. 해당 모드 동작이 완료될 때마다 DB에서 모드 및 구역 값을 읽고 해당 모드 동작을 반복함.
<br><br>

## 모드시나리오
스마트 공기청정기 모드별 시나리오를 설명한다. <br>
(추가 개발된 모드 외 로봇 개발 관련사항은 [seonghee-lee/Capstone](https://github.com/seonghee-lee/Capstone)을 참고)
- Selection mode: 사용자의 선택에 따라 희망하는 zone으로 이동하며 공기 정화<br><br>
- Autonomous highest zone mode: 모든 zone 자율주행하며 미세먼지 농도를 측정 후 최고 zone으로 자율주행하여 정화<br><br>
- Autonomous instant purification mode: 모든 zone을 자율주행하는 도중 각 zone에 도착했을 때, <br>미세먼지 농도 값이 0 ~ 30으로 좋음 상태일 때는 0분, 31 ~ 80으로 보통 상태일 때는 15분, 81 ~ 150으로 나쁨 상태일 때는 30분, 150이상으로 매우 나쁨 상태일 때는 60분 즉시 정화
<br><br>

## 해당논문
[Hyo-jin Shin, Ah-yeon Lim, Seong-hee Lee, Ji-hui Yun, "[Smart Autonomous Moving Air Purifier](https://doi.org/10.3745/PKIPS.y2021m11a.1239)", Proceedings of the Korea Information Processing Society Conference, Vol. 28, No. 2, pp1239-1241, Oct 2021.]

[임아연, 신효진 and 정의훈. (2022). [스마트 자율주행 공기청정기 시스템 개발](https://doi.org/10.7236/JIIBC.2022.22.2.109). 한국인터넷방송통신학회 논문지, 22(2), 109-114.]
<br><br>

## REFERENCE
- TURTLEBOT3 Github: https://github.com/ROBOTIS-GIT/turtlebot3
- TURTLEBOT3 e-manual: https://emanual.robotis.com/docs/en/platform/turtlebot3
- 안드로이드 스튜디오 mysql 연동: https://yoo-hyeok.tistory.com/18?category=708422
***
