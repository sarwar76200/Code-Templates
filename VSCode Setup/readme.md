## Add compiler to path
````
rundll32 sysdm.cpl,EditEnvironmentVariables
````
## Clangd args
````
-header-insertion=never
````
## Precompile header
````
g++ stdc++.h -Wall -std=c++20
````
## Code runner executor
````
"cpp": "cd $dir && run.bat $fileName $fileNameWithoutExt"
````
