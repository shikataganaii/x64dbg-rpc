# x64dbg-rpc  

<p align="center"><img src="https://github.com/user-attachments/assets/21206cd5-4828-49a7-aa00-764f6225ee05" /></p>  

## About  
A simple x64dbg plugin to show your current debugging session on Discord.  

## How to Install  
1. Download the latest [release](https://github.com/shikataganaii/x64dbg-rpc/releases).  
2. Open the directory where **x64dbg** is located.  
3. Navigate to the **x64** folder and move **x64dbg-rpc.dp64** to **x64/plugins**.  
4. Repeat step 3 for **x86** (move **x86dbg-rpc.dp86** to **x86/plugins**).  

> **Note:** If the **plugins** folder doesn't exist, simply create it.  

## How to Build  
1. Open the solution in **Visual Studio 2022**.  
2. Set the configuration:  
   - **Release | x64** for **x64dbg**  
   - **Release | x86** for **x86dbg**  
3. Compile the project.  
4. Rename the file extension for the compiled DLL:  
   - **.dp64** for **x64dbg**  
   - **.dp86** for **x32dbg**  
5. Test it out!
