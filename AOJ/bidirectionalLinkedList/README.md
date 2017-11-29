# ALDAS1_3_C Doubly Linked List BidirectionalLinkedList
<http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C&lang=jp>  
  
実装が汚いかも  
入力された"insert"などのコマンドを一々全て比較していると時間がかかってしまいTLEした(bkup.cpp)  
cinとかも少し遅いらしいが...  
strcmpなみに遅いはずなので、なるべく使用しないようにする。
5文字目と6文字目を見れば4つのコマンドの区別はつくのでそこだけ見れば早くおわる  
