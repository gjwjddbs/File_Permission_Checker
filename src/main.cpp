#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include "FileChecker.h"

int main(int argc,char **argv) {

    std::string fileName="";//파일 경로
    unsigned long standard=0;//보안 기준 권한

    //인수가 3개 이하일 경우
    if(argc<3){
        printf("Usage: %s <file_path> <standard_permission (octal, e.g., 644)>\n",argv[0]);
        return 1;
    }

    fileName=argv[1];
    standard=std::stoul(argv[2], nullptr, 8);

    //파일이 존재하는지 확인
    if(!FileCheck::file_exist(fileName)){
        printf("File does not exist at the specified path. Please try again.\n");
        return 0;
    }

    FileCheck *file = new FileCheck(fileName,standard);

    //파일 권한 확인
    file->file_perm();

    //파일 권한 검사
    file->perm_check(standard);
        
    //결과 출력
    file->PrintResult();

    delete(file);
}