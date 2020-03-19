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
        int i = 0, len = words.size();
        while (i < len) {
            int j = i;
            int curLen = 0;   //当前行的长度
            //加空格加下一个单词不超过maxWidth
            while (j < len && curLen+words[j].size()+j-i <= maxWidth) {
                curLen += words[j].size();
                ++j;
            }
            //当前行已经尽可能装满了
            int spaceNum = maxWidth - curLen;
            string curStr;
            int spaceInterval;
            //开始填单词
            for (int k = i; k < j; ++k) {
                curStr += words[k];
                //计算空格数
                if (j != len) {
                    //不是最后一行，则空格需要尽可能分散
                    if (j-k-1 > 0) {
                        if (spaceNum % (j-k-1) == 0) spaceInterval = spaceNum / (j-k-1);
                        else spaceInterval = spaceNum / (j-k-1) + 1;
                    }
                    else
                        spaceInterval = spaceNum;   //最后一个单词，直接后面补全空格
                }
                else {
                    //最后一行单独处理
                    if (j-k-1 == 0) spaceInterval = spaceNum;  //最后一个单词了
                    else spaceInterval = 1;
                }
                //统一添加空格
                curStr += string(spaceInterval, ' ');
                spaceNum -= spaceInterval;
            }
            //处理完一行了
            ans.push_back(curStr);
            i = j;
        }
        
        return ans;
    }
};
