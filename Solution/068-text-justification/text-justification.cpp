// Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is inserted between words.
//
// Note:
//
//
// 	A word is defined as a character sequence consisting of non-space characters only.
// 	Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// 	The input array words contains at least one word.
//
//
// Example 1:
//
//
// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
//
//
// Example 2:
//
//
// Input:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be",
//              because the last line must be left-justified instead of fully-justified.
//              Note that the second line is also left-justified becase it contains only one word.
//
//
// Example 3:
//
//
// Input:
// words = ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
//
//


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int len = words.size();
        while(i < len) {
            int j = i, tmplen = 0;
            //word的长度和word间的空格长度
            while(j < len && tmplen+words[j].size()+j-i <= maxWidth) {
                tmplen += words[j++].size();
            }
            string tmpstr;  //此时已经达到一行
            int spacenum = maxWidth - tmplen;
            for(int k = i; k < j; ++k) {
                //逐个插入word
                tmpstr += words[k];
                if(spacenum > 0) {
                    int tmp;
                    if(j==len) { //单独处理最后一行
                        if(j-k==1) tmp = spacenum; //最后一行的末尾补全空格
                        else tmp = 1;  //最后一行每个word间相隔1个空格
                    }
                    else {
                        //除最后一行外，各word间的空格数目均分
                        if (j - k - 1 > 0) {
                            if (spacenum % (j - k - 1) == 0) tmp = spacenum / (j - k - 1);
                            else tmp = spacenum / (j - k - 1) + 1;
                        } else tmp = spacenum;  //行末尾处
                    }
                    tmpstr.append(tmp,' ');  //添加空格
                    spacenum -= tmp;
                }
            }
            ans.push_back(tmpstr);
            i = j;
        }
        return ans;
    }
};
