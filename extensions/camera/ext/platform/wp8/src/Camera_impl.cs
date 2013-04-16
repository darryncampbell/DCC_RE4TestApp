using System;
using System.Collections.Generic;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace rho {

namespace CameraImpl
{
    public class Camera : CameraRuntime.ICameraImpl
    {
        public Camera()
        {
            var _runtime = new CameraRuntime.CameraRuntimeComponent(this);
        }

        public void enable(IReadOnlyDictionary<string, string> propertyMap, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void start(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void stop(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void disable(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void take(IReadOnlyDictionary<string, string> propertyMap, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getProperty(string propertyName, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getProperties(IReadOnlyList<string> arrayofNames, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getAllProperties(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setProperty(string propertyName, string propertyValue, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setProperties(IReadOnlyDictionary<string, string> propertyMap, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void clearAllProperties(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }

    public class CameraSingleton : CameraRuntime.ICameraSingletonImpl
    {
        public CameraSingleton()
        {
            var _runtime = new CameraRuntime.CameraSingletonComponent(this);
        }

        public void enumerate(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }
}

}
