## Try C/C++

1. Download and setup [Visual Studio](https://www.visualstudio.com/)
2. Create new project
3. paste code below and build project
  ```
  #include "windows.h"
  #include "tchar.h"

  int _tmain(int argc, TCHAR *argv[])
  {
  	MessageBox(NULL,
  			   L"Hello World!",
  			   L"www.reversecore.com",
  			   MB_OK);

  	return 0;
  }
  ```
4. compile project and check directory

  ```cd C:\Users\Woosungchu\Documents\Visual Studio 2017\Projects\ConsoleApplication1\Debug```
