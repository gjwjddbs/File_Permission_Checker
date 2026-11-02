#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "FileChecker.h"
#include <sys/stat.h>
#include <string>

FileCheck::FileCheck(std::string filename,unsigned long standard){
    this->filename=filename;
    this->standard=standard;
};

//파일 존재 유무
bool FileCheck::file_exist(std::string fileName){
    struct stat fileInfo;
    return stat(fileName.c_str(),&fileInfo)==0;
};

//파일 권한 확인
void FileCheck::file_perm(){
    struct stat fileInfo;
    if(stat(this->filename.c_str(),&fileInfo)!=0) return;
    this->perm = fileInfo.st_mode & 07777;
};

//권한 검사
void FileCheck::perm_check(unsigned long standard){
    
    unsigned long special = this->perm&07000;//특수 권한 존재 유무
    unsigned long basic = this->perm&0777;//일반 권한 존재 유무

    if ((basic & ~standard) == 0 && special==0){// 기준을 통과하는 경우
        this->status=Status::PASS;
        return;
    }

    if((basic & ~standard) != 0 && special==0){
        this->status=Status::FAIL;//기준을 통과하지 못하는 경우
        return;
    }

    if (special!=0) {// setuid/setgid/Stickybit: 수동 확인
        this->special_perm=true;
    }
    this->status = Status::WARN;
};    

//결과 출력
void FileCheck::PrintResult(){
    printf("=============================================\n");
    switch(this->status){
        case Status::PASS://안전
            printf("Diagnosis Result: Secure\n");
            break;
        case Status::FAIL://취약
            printf("Diagnosis Result: Vulnerable\n");
            break;
        case Status::WARN://수동 진단 필요
            printf("Diagnosis Result: Manual Inspection Required\n");
            if(this->special_perm){//특수 권한이 존재하는 경우
                printf("Setuid/ Setgid/ Sticky bit exist!\n");
            }
            break;
    };
    printf("File: %s Current Permission: %lo\n",this->filename.c_str(),this->perm);
    //권한 조치 필요
    if(this->status == Status::FAIL){
        printf("Remediation Instructions\n");
        printf("=> chmod %lo %s\n",this->standard,this->filename.c_str());
    }
    printf("=============================================");
};
