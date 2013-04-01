require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'

class KeyCaptureTestController < Rho::RhoController
  include BrowserHelper
  include ApplicationHelper
  
  
  def capture_key
	puts "Setting a Captured Key: #{@params['theCapturedKey']}, Dispatch?: #{@params['dispatchKey']}, ID: #{@params['id']}"
	theID = @params['id']
	if theID == "0"
		Rho::KeyCapture.captureKey(eval(@params['dispatchKey']), @params['theCapturedKey'], url_for(:action => :keyCallback0))
	elsif theID == "1"
		Rho::KeyCapture.captureKey(eval(@params['dispatchKey']), @params['theCapturedKey'], url_for(:action => :keyCallback1))
	elsif theID == "2"
		Rho::KeyCapture.captureKey(eval(@params['dispatchKey']), @params['theCapturedKey'], url_for(:action => :keyCallback2))
	elsif theID == "3"
		Rho::KeyCapture.captureKey(eval(@params['dispatchKey']), @params['theCapturedKey'], url_for(:action => :keyCallback3))
	end
  end
  
  def uncapture_key
	puts "Unsetting the capture for a key: #{@params['theCapturedKey']}, ID: #{@params['id']}"
	theID = @params['id']
	if theID == "0"
		Rho::KeyCapture.captureKey(false, @params['theCapturedKey'])
	elsif theID == "1"
		Rho::KeyCapture.captureKey(false, @params['theCapturedKey'])
	elsif theID == "2"
		Rho::KeyCapture.captureKey(false, @params['theCapturedKey'])
	elsif theID == "3"
		Rho::KeyCapture.captureKey(false, @params['theCapturedKey'])
	end  
  end
  
  def set_trigger
	puts "Setting a callback for the Trigger"
	Rho::KeyCapture.captureTrigger(url_for(:action => :triggerCallback))
  end

  def unset_trigger
	puts "Unsetting a callback for the Trigger"
	Rho::KeyCapture.captureTrigger
  end
  
  def setHome
	puts "Setting the Home Key to : #{@params['theKey']}"
	Rho::KeyCapture.homeKeyValue = @params['theKey']
	WebView.execute_js("outputToPage('messages', 'Changing Home Key to #{@params['theKey']}');")
  end

  def remapKeys
	puts "Remapping key from : #{@params['srcKey']} to #{@params['destKey']}"
	Rho::KeyCapture.remapKey(@params['srcKey'],@params['destKeyKey'])
	WebView.execute_js("outputToPage('messages', 'Remapping key from : #{@params['srcKey']} to #{@params['destKey']}');")
  end
  
  def triggerCallback
	puts "Trigger Callback Fired: #{@params}"
	WebView.execute_js("outputToPage('triggerState', 'Trigger Pressed.  flag: #{@params["triggerFlag"]}');")
  end
  
  def keyCallback0
	puts "All Keys Callback Fired: #{@params}"
	WebView.execute_js("outputToPage('keyStateAll', 'Event Fired.  Pressed Key: #{@params["keyValue"]}');")
  end  
  
  def keyCallback1
	puts "A Key Callback Fired: #{@params}"
	WebView.execute_js("outputToPage('keyStateA', 'Event Fired.  Pressed Key: #{@params["keyValue"]}');")
  end  
  
  def keyCallback2
	puts "1 Key Callback Fired: #{@params}"
	WebView.execute_js("outputToPage('keyStateOne', 'Event Fired.  Pressed Key: #{@params["keyValue"]}');")
  end  
  
  def keyCallback3
	puts "Q Key Callback Fired: #{@params}"
	WebView.execute_js("outputToPage('keyStateQ', 'Event Fired.  Pressed Key: #{@params["keyValue"]}');")
  end  
  
  
end
