# 問題
<http://codeforces.com/gym/101630/attachments/download/6401/20172018-acmicpc-northeastern-european-regional-contest-neerc-17-en.pdf>
<http://neerc.ifmo.ru/archive/2017/neerc-2017-analysis.pdf>

## B-Box
直方体の展開図は、各a,b,cについて11通りある。しかし実は11種類のうち2種類だけをチェックすれば良い。  
よってa, b, cと、w, h の順番をそれぞれ入れ替えて、  
2a+2b <= h  and  b+2c <= w  
a+c <= h and 3b+a+c <= w  
のいずれかが真であるかチェックする。  
もちろん、2種類だけでなく全てを試しても間に合うらしい。  

