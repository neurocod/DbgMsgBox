Suppose you want to show message box for debug reason, and either
1) you have console app without GUI
2) your GUI app does not allow to copy text from message boxes
3) your GUI app does not format json in message box

Then all you need is:
1) Open main.cpp from this project and copy launch function
2) build  this solution
3) call, something like:
  msgBox(R"({"name":"param1","param2":6,"arr":[1, 2, 3]})");
  
Plain text with original input:
![image](https://user-images.githubusercontent.com/2953741/77858348-a401a780-720b-11ea-8a6f-61a9988a3fdc.png)
Detected json:
![image](https://user-images.githubusercontent.com/2953741/77858374-d4e1dc80-720b-11ea-9882-18aeff4c6532.png)
