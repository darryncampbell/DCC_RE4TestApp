require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'

class SystemTestController < Rho::RhoController
  include BrowserHelper
  include ApplicationHelper
  
  def get_oem
	puts "Retrieving OEM"
	theOem = Rho::System.oemInfo
	puts "OEM Info Retrieved: #{theOem}"
	WebView.execute_js("outputToPage('Retrieved OEM #{theOem}');")
  end
  
  def get_uuid
	puts "Retrieving UUID"
	theUuid = Rho::System.uuid
	puts "UUID Retrieved: #{theUuid}"
	WebView.execute_js("outputToPage('Retrieved UUID #{theUuid}');")
  end
  
  def get_registry
	puts "Retrieving Registry Setting for #{@params['regHive']}, #{@params['regSubkey']}, #{@params['regSetting']}"
	theRegSetting = Rho::System.getRegistrySetting(Integer(@params['regHive']), @params['regSubkey'], @params['regSetting'])
	puts "Registry Setting retrieved: #{theRegSetting}"
	WebView.execute_js("outputToPage('Retrieved Registry Setting #{theRegSetting}');")
  end
  

  def set_registry
	puts "Setting Registry Setting for #{@params['regHive']}, #{@params['regType']}, #{@params['regSubkey']}, #{@params['regSetting']}, #{@params['regValue']}, persistent: #{@params['regPersistent']}"
	theRegSetting = Rho::System.setRegistrySetting(Integer(@params['regHive']), Integer(@params['regType']), @params['regSubkey'], @params['regSetting'], @params['regValue'])
#	theRegSetting = Rho::System.setRegistrySetting(Integer(@params['regHive']), Integer(@params['regType']), @params['regSubkey'], @params['regSetting'], @params['regValue'], eval(@params['regPersistent']))
	puts "Registry Setting Success?: #{theRegSetting}"
	WebView.execute_js("outputToPage('Set Registry Setting Success? #{theRegSetting}');")
  end
  
  def delete_registry
	puts "Deleting Registry Setting for #{@params['regHive']}, #{@params['regSubkey']}, #{@params['regSetting']}, persistent: #{@params['regPersistent']}"
	theRegSetting = Rho::System.deleteRegistrySetting(Integer(@params['regHive']), @params['regSubkey'], @params['regSetting'], eval(@params['regPersistent']))
	WebView.execute_js("outputToPage('Delete Registry Setting Success? #{theRegSetting}');")
  end
  
    def get_registry_sync
	puts "Retrieving Registry Setting for #{@params['regHive']}, #{@params['regSubkey']}, #{@params['regSetting']}"
	theRegSetting = Rho::System.getRegistrySetting({hive:@params['regHive'], key:@params['regSubkey'], setting:@params['regSetting']})
	puts "Registry Setting retrieved: #{theRegSetting}"
	render :json => theRegSetting
	return theRegSetting
  end
  
  def set_registry_sync
	puts "Setting Registry Setting for #{@params['regHive']}, #{@params['regType']}, #{@params['regSubkey']}, #{@params['regSetting']}, #{@params['regValue']}, persistent: #{@params['regPersistent']}"
	theRegSetting = Rho::System.setRegistrySetting({hive:@params['regHive'], type:@params['regType'], key:@params['regSubkey'], setting:@params['regSetting'], value:@params['regValue'], persistent:eval(@params['regPersistent'])})
#	theRegSetting = Rho::System.setRegistrySetting(Integer(@params['regHive']), Integer(@params['regType']), @params['regSubkey'], @params['regSetting'], @params['regValue'], eval(@params['regPersistent']))
	puts "Registry Setting Success?: #{theRegSetting}"
	returnValue = "false"
	if theRegSetting == true
		returnValue = "true"
	end
	render :json => returnValue
	return returnValue
  end
  
  def delete_registry_sync
	puts "Deleting Registry Setting for #{@params['regHive']}, #{@params['regSubkey']}, #{@params['regSetting']}, persistent: #{@params['regPersistent']}"
	theRegSetting = Rho::System.deleteRegistrySetting({hive:@params['regHive'], key:@params['regSubkey'], setting:@params['regSetting'], persistent:eval(@params['regPersistent'])})
#	theRegSetting = Rho::System.deleteRegistrySetting(Integer(@params['regHive']), @params['regSubkey'], @params['regSetting'], eval(@params['regPersistent']))
	returnValue = "false"
	if theRegSetting == true
		returnValue = "true"
	end
	render :json => returnValue
	return returnValue
  end


  def get_keyboard
	puts "Retrieving Keyboard Setting"
	theKeyboard = Rho::System.keyboardState
	render :json => theKeyboard
	return theKeyboard
  end

  def set_keyboard
	puts "Setting Keyboard State to: #{@params['keyboardState']}"
	Rho::System.keyboardState = @params['keyboardState']
	returnValue = "false"
#	if theKeyboard == true
#		returnValue = "true"
#	end
	render :json => returnValue
	return returnValue
  end

  
end
