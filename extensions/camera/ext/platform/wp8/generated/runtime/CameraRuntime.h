#pragma once

#include "../../../../shared/generated/cpp/ICamera.h"

namespace rho {

namespace CameraRuntime
{
    public interface class IMethodResult
    {
    public:
        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
        void set(Platform::String^ res);
        void set(Windows::Foundation::Collections::IVectorView<Platform::String^>^ res);
        void set(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ res);
    };

    public interface class ICameraImpl
    {
    public:
        void getCameraType(IMethodResult^ oResult);
        void getMaxWidth(IMethodResult^ oResult);
        void getMaxHeight(IMethodResult^ oResult);
        void getDesiredWidth(IMethodResult^ oResult);
        void setDesiredWidth(int desiredWidth, IMethodResult^ oResult);
        void getDesiredHeight(IMethodResult^ oResult);
        void setDesiredHeight(int desiredHeight, IMethodResult^ oResult);
        void getCompressionFormat(IMethodResult^ oResult);
        void setCompressionFormat(Platform::String^ compressionFormat, IMethodResult^ oResult);
        void getOutputFormat(IMethodResult^ oResult);
        void setOutputFormat(Platform::String^ outputFormat, IMethodResult^ oResult);
        void getColorModel(IMethodResult^ oResult);
        void setColorModel(Platform::String^ colorModel, IMethodResult^ oResult);
        void getEnableEditing(IMethodResult^ oResult);
        void setEnableEditing(bool enableEditing, IMethodResult^ oResult);
        void getFlashMode(IMethodResult^ oResult);
        void setFlashMode(Platform::String^ flashMode, IMethodResult^ oResult);
        void getSaveToSharedGallery(IMethodResult^ oResult);
        void setSaveToSharedGallery(bool saveToSharedGallery, IMethodResult^ oResult);
        void getCaptureSound(IMethodResult^ oResult);
        void setCaptureSound(Platform::String^ captureSound, IMethodResult^ oResult);
        void getPreviewLeft(IMethodResult^ oResult);
        void setPreviewLeft(int previewLeft, IMethodResult^ oResult);
        void getPreviewTop(IMethodResult^ oResult);
        void setPreviewTop(int previewTop, IMethodResult^ oResult);
        void getPreviewWidth(IMethodResult^ oResult);
        void setPreviewWidth(int previewWidth, IMethodResult^ oResult);
        void getPreviewHeight(IMethodResult^ oResult);
        void setPreviewHeight(int previewHeight, IMethodResult^ oResult);
        void takePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        void getProperty(Platform::String^ propertyName, IMethodResult^ oResult);
        void getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult);
        void getAllProperties(IMethodResult^ oResult);
        void setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult);
        void setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        void clearAllProperties(IMethodResult^ oResult);
    };

    public interface class ICameraSingletonImpl
    {
    public:
        void enumerate(IMethodResult^ oResult);
        void getCameraByType(Platform::String^ cameraType, IMethodResult^ oResult);
        void choosePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        void saveImageToDeviceGallery(Platform::String^ pathToImage, IMethodResult^ oResult);
    };

    public ref class CameraRuntimeComponent sealed: public ICameraImpl
    {
    public:
        CameraRuntimeComponent(ICameraImpl^ impl);
        virtual void getCameraType(IMethodResult^ oResult);
        virtual void getMaxWidth(IMethodResult^ oResult);
        virtual void getMaxHeight(IMethodResult^ oResult);
        virtual void getDesiredWidth(IMethodResult^ oResult);
        virtual void setDesiredWidth(int desiredWidth, IMethodResult^ oResult);
        virtual void getDesiredHeight(IMethodResult^ oResult);
        virtual void setDesiredHeight(int desiredHeight, IMethodResult^ oResult);
        virtual void getCompressionFormat(IMethodResult^ oResult);
        virtual void setCompressionFormat(Platform::String^ compressionFormat, IMethodResult^ oResult);
        virtual void getOutputFormat(IMethodResult^ oResult);
        virtual void setOutputFormat(Platform::String^ outputFormat, IMethodResult^ oResult);
        virtual void getColorModel(IMethodResult^ oResult);
        virtual void setColorModel(Platform::String^ colorModel, IMethodResult^ oResult);
        virtual void getEnableEditing(IMethodResult^ oResult);
        virtual void setEnableEditing(bool enableEditing, IMethodResult^ oResult);
        virtual void getFlashMode(IMethodResult^ oResult);
        virtual void setFlashMode(Platform::String^ flashMode, IMethodResult^ oResult);
        virtual void getSaveToSharedGallery(IMethodResult^ oResult);
        virtual void setSaveToSharedGallery(bool saveToSharedGallery, IMethodResult^ oResult);
        virtual void getCaptureSound(IMethodResult^ oResult);
        virtual void setCaptureSound(Platform::String^ captureSound, IMethodResult^ oResult);
        virtual void getPreviewLeft(IMethodResult^ oResult);
        virtual void setPreviewLeft(int previewLeft, IMethodResult^ oResult);
        virtual void getPreviewTop(IMethodResult^ oResult);
        virtual void setPreviewTop(int previewTop, IMethodResult^ oResult);
        virtual void getPreviewWidth(IMethodResult^ oResult);
        virtual void setPreviewWidth(int previewWidth, IMethodResult^ oResult);
        virtual void getPreviewHeight(IMethodResult^ oResult);
        virtual void setPreviewHeight(int previewHeight, IMethodResult^ oResult);
        virtual void takePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        virtual void getProperty(Platform::String^ propertyName, IMethodResult^ oResult);
        virtual void getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult);
        virtual void getAllProperties(IMethodResult^ oResult);
        virtual void setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult);
        virtual void setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        virtual void clearAllProperties(IMethodResult^ oResult);
    private:
        ICameraImpl^ _impl;
    };

    public ref class CameraSingletonComponent sealed: public ICameraSingletonImpl
    {
    public:
        CameraSingletonComponent(ICameraSingletonImpl^ impl);
        virtual void enumerate(IMethodResult^ oResult);
        virtual void getCameraByType(Platform::String^ cameraType, IMethodResult^ oResult);
        virtual void choosePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
        virtual void saveImageToDeviceGallery(Platform::String^ pathToImage, IMethodResult^ oResult);
    private:
        ICameraSingletonImpl^ _impl;
    };
}

}
