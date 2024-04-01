
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace SaltRoadLib
{
    public class SaltRoad
    {
        [DllImport("SaltRoadFrameworkLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int saltroad_add(int x, int y);
        public int add(int x, int y) {
            return saltroad_add(x, y);
        }
        
        [DllImport("SaltRoadFrameworkLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern string saltroad_uppercase(string str);
        public string uppercase(string str) {
            return saltroad_uppercase(str);
        }
        
        [DllImport("SaltRoadFrameworkLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern string saltroad_jsonpath(string path, string json);
        public string jsonpath(string path, string json) {
            return saltroad_jsonpath(path, json);
        }

        public SaltRoad() {

            // TODO: figure out the correct method for embedding DLL's into the VS project for bundling with the library
            var path = Environment.GetEnvironmentVariable("PATH");
            var dllDirectory = "C:\\Users\\rocco\\Development\\SaltRoad\\VSSaltRoadLib\\SaltRoadLib\\DLL";
            Environment.SetEnvironmentVariable("PATH", Environment.GetEnvironmentVariable("PATH") + ";" + dllDirectory);

            var x = add(40, 2);
            Trace.WriteLine(String.Format("TAG: the value is {0}", x));
            
            var hello = uppercase("hello world!");
            Trace.WriteLine(String.Format("TAG: uppercase: {0}", hello));

            var results = jsonpath("$[3,6,-2]", "[0,1,2,3,4,5,6,7,8,9]");
            Trace.WriteLine(String.Format("TAG: jsonpath: {0}", results));
        }
    }
}
