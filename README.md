# File_Permission_Checker

## 목표

- 프로젝트의 목표는 리눅스 환경에서 파일의 권한을 검사하고 결과에 따른 보안 대책을 구하는 것이다. 
<br>

## 📆 제작 기간

- 26.10.26일 ~ 26.11.02일
<br>

## 🔧 주요 기능
- 우선 파일을 검사하기 검사 파일의 이름과 보안 권장 기준을 입력한다.<br>
  - ex) ./[프로그램명] [파일 경로] [권장 기준]<br>
- 그럼 다음 파일의 존재 유무를 확인하고 존재하지 않으면, 파일을 종료한다.<br>
- 파일이 존재하면 경로에 존재하는 파일의 권한을 검사하고 다음과 같은 기준으로 판단한다.<br>
  - PASS: 파일이 권장 기준보다 적은 권한을 가지는 경우<br>
  - FAIL: 파일이 권장 기준보다 큰 권한을 가지는 경우<br>
  - WARN: 파일이 특수 권한(SUID/SGID/Sticky Bit)을 가지고 있어 수동 진단이 필요한 경우<br>
- 검사 결과를 출력해준다.

<br>

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
    └─FileChecker.cpp
    └─main.cpp
    └─build
        └─Debug
    
```
<br>
