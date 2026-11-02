# 간단한 파일 권한 검색기

## 목표

- 프로젝트의 목표는 리눅스 환경에서 파일의 권한을 검사하고 결과에 따른 보안 대책을 구하는 것이다. 
<br>

## 📆 제작 기간

- 26.10.26일 ~ 26.11.02일
<br>

## 🔧 주요 기능
- 우선 파일을 검사하기 검사 파일의 이름과 보안 권장 기준을 입력한다.<br>
  - ex) <b>./[프로그램명] [파일 경로] [권장 기준]</b><br>
- 그럼 다음 파일의 존재 유무를 확인하고 존재하지 않으면, 프로그램을 종료한다.<br>
- 파일이 존재하면 경로에 존재하는 파일의 권한을 검사하고 다음과 같은 기준으로 판단한다.<br>
  - <b>PASS</b> : 파일이 권장 기준보다 적은 권한을 가지는 경우<br>
  - <b>FAIL</b> : 파일이 권장 기준보다 큰 권한을 가지는 경우<br>
  - <b>WARN</b> : 파일이 특수 권한(SUID/SGID/Sticky Bit)을 가지고 있어 수동 진단이 필요한 경우<br>
- 검사 결과를 출력한다.<br>
</br>

## 구현
### 프로그램 실행
> <img width="380" height="142" alt="image" src="https://github.com/user-attachments/assets/16aefc85-56be-46ad-84d4-af6fa34b561c" />
-  <b>./[프로그램명] [파일 경로] [권장 기준]</b> 형식으로 프로그램을 실행한다.
### 안전
> <img width="396" height="111" alt="image" src="https://github.com/user-attachments/assets/2199df89-2e61-45e2-b4ed-d9c2ff6fdc75" />
- 파일의 권한이 권장 기준보다 적은 권한을 가지는 경우, 안전한다고 판단하고 현재 파일의 권한을 출력한다.
### 취약
> <img width="389" height="137" alt="image" src="https://github.com/user-attachments/assets/4a1fb043-cf39-4cc6-b8a3-ae433389c180" />
- 파일의 권한이 권장 기준보다 많은 권한을 가지는 경우, 취약으로 판단하고 현재 파일의 권한과 권한 변경 메시지를 출력한다.
### 수동 진단 필요
> <img width="377" height="116" alt="image" src="https://github.com/user-attachments/assets/fd96ad79-b00d-4fd1-94ae-37ca53ae5932" />
- 파일에 특수 권한(SUID/SGID/Sticky Bit)을 가지는 경우, 수동 진단이 필요하다고 판단한다.
</br>

## 빌드 및 실행
1. 컴파일
```bash
g++ -std=c++17 -g -Wall -Iinclude src/main.cpp src/FileChecker.cpp -o checkperm
```
- 리눅스 환경에서 컴파일을 통해 실행 파일을 생성한다.
</br>

2. 실행  
```bash
./[프로그램명] [파일 경로] [권장 기준]
```
- 점검 파일 경로와 보안 권장 기준을 입력한다.

</br>

## 🛠️ 기술 스택

### 언어
<div>
  <img src="https://img.shields.io/badge/-C++-000000?logo=c%2B%2B&style=flat">
</div>

### 형상 관리
<div>
    <img src="https://img.shields.io/badge/GiHub-181717?style=for-the-badge&logo=GitHub&logoColor=white">
</div>
<br>

## 📂 프로젝트 구조
```bash
FileChecker
├─build
│  └─Debug
├─include
    └─FileChecker.h
└─src
    └─FileChecker.cpp //파일 점검 기능 구현
    └─main.cpp //프로그램 실행부
    └─build
        └─Debug
    
```
<br>
