// Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
//
// In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
//
// Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
//
//  
//
// Example 1:
//
//
// Input: "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.
//
//
// Example 2:
//
//
// Input: "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
//
//
// Example 3:
//
//
// Input: "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
//
//
// Example 4:
//
//
// Input: "/a/./b/../../c/"
// Output: "/c"
//
//
// Example 5:
//
//
// Input: "/a/../../b/../c//.//"
// Output: "/c"
//
//
// Example 6:
//
//
// Input: "/a//b////c/d//././/.."
// Output: "/a/b/c"
//
//


class Solution {
public:
    string simplifyPath(string path) {
        //总结一下规律：对于.不做操作，对于..则弹出上一个临近的目录，其余的直接放进数组即可
        vector<string> dirs;
        string ans;
        if(path.empty()) return ans;
        
        int len = path.size();
        int i = 0;
        while(i < len) {
            while(i < len && path[i]=='/') ++i;  //连续的/只计算一个
            if(i >= len) break;
            int start = i;  //找/分割的子字符串
            while(i < len && path[i]!='/') ++i;
            int end = i - 1;
            string tmp = path.substr(start,end-start+1);
            if(tmp=="..") {
                if(!dirs.empty()) dirs.pop_back();
            }
            else if(tmp != ".") {
                dirs.push_back(tmp);
            }
        }
        
        if(dirs.empty()) return "/";  //example2
        for(string s : dirs) ans += '/'+s;
        return ans;
    }
};
