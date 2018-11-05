//
//  getPath.hpp
//  jRPG
//
//  Created by Антон on 16.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef _GET_PATH_H_
#define _GET_PATH_H_

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd // stupid MSFT "deprecation" warning
#else
#include <unistd.h>
#endif
#include <string>
#include <iostream>


class GetPath {
public:
    static std::string as_string() {
        char buffer[255];
        char *answer = getcwd(buffer, sizeof(buffer));
        std::string s_cwd;
        if (answer)
        {
            s_cwd = answer;
            return s_cwd;
        }
        else return NULL;
    }
    static char* as_char() {
        char buffer[255];
        char *answer = getcwd(buffer, sizeof(buffer));
        std::string s_cwd;
        if (answer)
            return answer;
        else return NULL;
    }
    
    
};


#endif /* _GET_PATH_H_ */
