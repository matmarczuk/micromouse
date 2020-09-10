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

![Main window](https://user-images.githubusercontent.com/26739110/92818074-9316ae00-f3c7-11ea-9a53-bebb77c26df8.png)
Hit start to begin board scanning. Main interface displays current state of mouse.
After scan is finished user can choose algorithm to solve recorded board. After that click SOLVE AND RIDE button to enable mouse to ride resolved path. 

![Solve](https://user-images.githubusercontent.com/26739110/92818244-c5281000-f3c7-11ea-9f50-eaf81df5bd13.png)
