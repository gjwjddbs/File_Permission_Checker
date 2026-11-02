#pragma once
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string>

enum class Status{
    WARN,
    PASS,
    FAIL
};

class FileCheck{
    private:
        std::string filename;//파일 경로
        Status status;//점검 결과
        unsigned long standard;//보안 기준 권한
        unsigned long perm;//파일 권한
        bool special_perm=false;//특수 권한(setuid, setgid, sticky bit) 존재 유무
    public:
        FileCheck(std::string fileName, unsigned long standard);
        //파일 존재 유무
        static bool file_exist(std::string fileName);
        //파일 권한 확인
        void file_perm();
        //권한 확인
        void perm_check(unsigned long standard);
        //결과 출력
        void PrintResult();
};

