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

        public void getCameraType(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getMaxWidth(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getMaxHeight(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getDesiredWidth(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setDesiredWidth(int desiredWidth, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getDesiredHeight(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setDesiredHeight(int desiredHeight, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getCompressionFormat(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setCompressionFormat(string compressionFormat, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getOutputFormat(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setOutputFormat(string outputFormat, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getColorModel(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setColorModel(string colorModel, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getEnableEditing(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setEnableEditing(bool enableEditing, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getFlashMode(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setFlashMode(string flashMode, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getSaveToSharedGallery(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setSaveToSharedGallery(bool saveToSharedGallery, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getCaptureSound(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setCaptureSound(string captureSound, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getPreviewLeft(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setPreviewLeft(int previewLeft, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getPreviewTop(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setPreviewTop(int previewTop, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getPreviewWidth(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setPreviewWidth(int previewWidth, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void getPreviewHeight(CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void setPreviewHeight(int previewHeight, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void takePicture(IReadOnlyDictionary<string, string> propertyMap, CameraRuntime.IMethodResult oResult)
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

        public void getCameraByType(string cameraType, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void choosePicture(IReadOnlyDictionary<string, string> propertyMap, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void saveImageToDeviceGallery(string pathToImage, CameraRuntime.IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }
}

}
