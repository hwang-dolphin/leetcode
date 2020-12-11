/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
var arrayStringsAreEqual = function(word1, word2) {
    let wordResult1;
    let wordResult2;
        
    let result;
        
        for (let i = 0; i < word1.length; i++)
        {
           wordResult1 = wordResult1 + word1[i];
        }
        
        for (let i = 0; i < word2.length; i++)
        {
            wordResult2 = wordResult2 + word2[i];
        }
        
        if (wordResult1 == wordResult2)
        {
            result = true;
        }
        
        else
        {
            result = false;
        }
        
        return result;
    
};


word1 = ["a", "cb"];
word2 = ["ab", "c"];

let answer = arrayStringsAreEqual(word1, word2);

console.log(answer);
