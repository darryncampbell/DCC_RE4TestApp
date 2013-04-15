require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'

class CameraTestController < Rho::RhoController
  include BrowserHelper
  include ApplicationHelper
  
  def get_maximum_width
	puts "Getting Maximum Camera Width"
	maxWidth = Rho::Camera.maxWidth
	returnValue = maxWidth
#	if theRegSetting == true
#		returnValue = "true"
#	end
	render :json => returnValue
	return returnValue  
  end
  
  def get_maximum_height
	puts "Getting Maximum Camera Height"
	maxWidth = Rho::Camera.maxHeight
	returnValue = maxHeight
	render :json => returnValue
	return returnValue  
  end
  
  def set_property
	# Also consider desiredHeight and desiredWidth parameters
	puts "Setting Camera Property #{@params['theProperty']} to value #{@params['chosenValue']}"
	myProps = Hash.new
	myProps[@params['theProperty']] = @params['chosenValue']
	Rho::Camera.setProperty
  end
  
  def enumerateCameras
	puts "Enumerating Cameras on Device"
	WebView.execute_js("clearCameraEnumeration();")
	arCameras = Rho::Camera.enumerate
	arCameras.each {|x| WebView.execute_js("addCameraToEnumeration('" + x.getProperty('cameraType') + "');")}
	arCameras.each {|x| puts x.getProperty('cameraType') }
  end
  
  def setDefaultCamera
	arCameras = Rho::Camera.enumerate
	arCameras.each {|x| if @params['specifiedCamera'] == x.getProperty('cameraType') then Rho::Camera.setDefault(x) end}
  end
  
  def take_picture
	Rho::Camera.takePicture(@params, url_for(:action => :pictureEvent))
  end
  
  def pictureEvent
	puts "Take Picture Event Fired: #{@params}"
	WebView.execute_js("cameraCallback(#{@params["status"]}, #{@params["imageUri"]}, #{@params["imageHeight"]}, #{@params["imageWidth"]}, #{@params["imageFormat"]}, #{@params["message"]});")
  end
  

  
end
