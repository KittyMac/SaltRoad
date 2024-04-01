
using System.Runtime.InteropServices;

namespace SaltRoadLib
{
    

    public class Class1
    {
        // [DllImport("Foundation.dll")]
        [DllImport("SaltRoadFrameworkLib.dll")]
        public static extern int saltroad_add(int x, int y);

        public Class1() {

            // C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Program Files\dotnet\;C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit\;C:\Users\rocco\AppData\Local\Programs\Python\Python39\Scripts\;C:\Users\rocco\AppData\Local\Programs\Python\Python39\;C:\Users\rocco\AppData\Local\Microsoft\WindowsApps;C:\Users\rocco\AppData\Local\Programs\Swift\Runtimes\5.10.0\usr\bin\;C:\Users\rocco\AppData\Local\Programs\Swift\Toolchains\5.10.0+Asserts\usr\bin\;C:\Users\rocco\AppData\Local\Programs\Swift\Tools\5.10.0\;C:\Users\rocco\.dotnet\tools
            // {"Unable to load DLL 'SaltRoadFramework.dll' or one of its dependencies: The specified module could not be found. (0x8007007E)"}
            var path = Environment.GetEnvironmentVariable("PATH");

            var dllDirectory = "C:\\Users\\rocco\\Development\\SaltRoad\\VSSaltRoadLib\\SaltRoadLib\\DLL";
            Environment.SetEnvironmentVariable("PATH", Environment.GetEnvironmentVariable("PATH") + ";" + dllDirectory);


            int result = saltroad_add(2, 40);
            Console.WriteLine(result);
        }
    }

}
