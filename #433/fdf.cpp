// #include <iostream>
// #include <string>

// int main ()
// {
//   std::string str ("This is an example sentence.");
//   std::cout << str << '\n';
//                                            // "This is an example sentence."
//   str.erase (10,8);                        //            ^^^^^^^^
//   std::cout << str << '\n';
//                                            // "This is an sentence."
//   str.erase (str.begin()+9);               //           ^
//   std::cout << str << '\n';
//                                            // "This is a sentence."
//   str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
//   std::cout << str << '\n';
//                                            // "This sentence."
//   return 0;
// }
#include <iostream>
#include <string>

int main ()
{
  std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;

  // used in the same order as described above:
   std::cout << str << '\n';
  str.insert(6,str2);    
   std::cout << str << '\n';             // to be (the )question
  str.insert(6,str3,3,4);   
   std::cout << str << '\n';          // to be (not )the question
  str.insert(10,"that is cool",8);
   std::cout << str << '\n';    // to be not (that is )the question
  str.insert(10,"to be ");  
   std::cout << str << '\n';          // to be not (to be )that is the question
  str.insert(15,1,':');     
   std::cout << str << '\n';          // to be not to be(:) that is the question
  it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  str.insert (it+2,str3.begin(),str3.begin()+3); // (or )

  std::cout << str << '\n';
  return 0;
}