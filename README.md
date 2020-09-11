# Micromouse simulator
App was created within one of student curse subject

# Build instruction 
`mkdir build`

`cd build`

`qmake ../<reference to .pro file>`

`make`

`./micromouse`

# Usage 
Once user launches an app it will see opening screen. It will allow to generate new map or load it from json file. 

![Load screen](https://user-images.githubusercontent.com/26739110/92817938-6bbfe100-f3c7-11ea-92a5-7d40c555450b.png)

User can choose to generate new square map between 4 to 16 cell dimension

![Generate board](https://user-images.githubusercontent.com/26739110/92818022-82fece80-f3c7-11ea-8894-be167ed33b3b.png)
After that new map will be generated. Main app window will be opened. 

![Main window](https://user-images.githubusercontent.com/26739110/92899606-3e068680-f41f-11ea-917c-949fb49815f4.png)
Hit SCAN to begin board scanning. Main interface displays current state of mouse.
After scan is finished user can choose algorithm to solve recorded board. After that click SOLVE AND RIDE button to enable mouse to ride resolved path. 

![Solve](https://user-images.githubusercontent.com/26739110/92901737-00a2f880-f421-11ea-82be-6be5725527ae.png)
