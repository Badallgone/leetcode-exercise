/*
 * @lc app=leetcode.cn id=71 lang=c
 *
 * [71] 简化路径
 */

// @lc code=start
char* simplifyPath(char* path) {
    int len = strlen(path);
    char *res = (char*)malloc(sizeof(char) * (len + 1));
    char tmp[1600][30];
    int index = 0;
    char token[256];
    int tokenIndex = 0; 
    for(int i=0;i<len;i++) {
        if(path[i] == '/') {
            if(tokenIndex > 0) {
                token[tokenIndex] = '\0';
                if(strcmp(token, ".") == 0) {
                    // do nothing
                } else if(strcmp(token, "..") == 0) {
                    if(index > 0) {
                        index--;
                    }
                } else {
                    strcpy(tmp[index++], token);
                }
                tokenIndex = 0;
            }
        } else {
            token[tokenIndex++] = path[i];
        }
    }
    // Handle the last token
    if(tokenIndex > 0) {
        token[tokenIndex] = '\0';
        if(strcmp(token, ".") == 0) {
            // do nothing
        } else if(strcmp(token, "..") == 0) {
            if(index > 0) {
                index--;
            }
        } else {
            strcpy(tmp[index++], token);
        }
    }

    // Build the result string
    res[0] = '\0';
    for(int i = 0; i < index; i++) {
        strcat(res, "/");
        strcat(res, tmp[i]);
    }
    if(strlen(res) == 0) {
        strcpy(res, "/");
    }
    return res;
}
// @lc code=end

