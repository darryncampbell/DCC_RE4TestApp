require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'
#require 'barcode'
#require 'networkaccess'

class NetworkTestController < Rho::RhoController
  include BrowserHelper
  include ApplicationHelper
  
  def test_proc(arg)
    puts "test_proc : #{arg}"
  end
  
  def run_test
    my_test = "my_test"
	puts @params['host']
	Rho::Network.cancel
#	WebView.execute_js("alert('Received a Value #{@params[0]}');")
	
    #render :action => :index
  end
  
  def connection_test1
	puts "Connection Test 1"
	myProps = Hash.new
	myProps['host'] = 'http://www.facebook.com'
	myProps['port'] = 80
	myProps['pollInterval'] = 5000
	myProps['detectionTimeout'] = 1000
	Rho::Network.detectConnection('http://www.facebook.com', 80, 5000, 1000, url_for(:action => :connectionEvent))
  end

  def connection_test2
	puts "Connection Test 2"
#	Rho::Network.detectConnection('192.168.44.128', 8083, 5000, 1000, url_for(:action => :connectionEvent))
	myPort = 1
	myPort = @params['port']
	Rho::Network.detectConnection('127.0.0.1', Integer(myPort), 5000, 1000, url_for(:action => :connectionEvent))
  end
  
  def connection_test_stop1
	puts "Stop Connection Test 1"
	Rho::Network.stopDetectingConnection(url_for(:action => :connectionEvent1))
  end
  
  def connection_test_stop2
	puts "Stop Connection Test 2"
	Rho::Network.stopDetectingConnection(url_for(:action => :connectionEvent2))
  end
  
  def connection_test_stop3
	puts "Stop Connection Test 3"
	Rho::Network.stopDetectingConnection(url_for(:action => :connectionEvent3))
  end
  
  def postEvent
	puts "PostEvent #{@params}"
  end
  
  def wm_connection_test1
	puts "Connection Test 1"
	myProps = Hash.new
	myProps['host'] = @params['host']
	myProps['port'] = @params['port']
	myProps['pollInterval'] = 5000
	myProps['detectionTimeout'] = 1000
	Rho::Network.detectConnection(myProps, url_for(:action => :connectionEvent1))  
  end
  
  def wm_connection_test2
	puts "Connection Test 2"
	myProps = Hash.new
	myProps['host'] = @params['host']
	myProps['port'] = @params['port']
	myProps['pollInterval'] = 7000
	myProps['detectionTimeout'] = 1000
	Rho::Network.detectConnection(myProps, url_for(:action => :connectionEvent2))  
  end
  
  def wm_connection_test3
	puts "Connection Test 3"
	myProps = Hash.new
	myProps['host'] = @params['host']
	myProps['port'] = @params['port']
	myProps['pollInterval'] = 8000
	myProps['detectionTimeout'] = 1000
	Rho::Network.detectConnection(myProps, url_for(:action => :connectionEvent3))  
  end
  
  def connectionEvent1
	puts "ConnectionEvent 1 Called #{@params}"
	WebView.execute_js("connectionEvent1('Received a Value #{@params["connectionInformation"]}', '#{@params["failureMessage"]}');")
  end

  def connectionEvent2
	puts "ConnectionEvent 2 Called #{@params}"
	WebView.execute_js("connectionEvent2('Received a Value #{@params["connectionInformation"]}', '#{@params["failureMessage"]}');")
  end

  def connectionEvent3
	puts "ConnectionEvent 3 Called #{@params}"
	WebView.execute_js("connectionEvent3('Received a Value #{@params["connectionInformation"]}', '#{@params["failureMessage"]}');")
  end

  
  def http_post_test_1
	puts "HTTP Post Test 1"
	myHeaders = Hash.new
	# 28 is the length of body
	myHeaders['Content-Length'] = 28
	
	myProps = Hash.new
	myProps['url'] = 'http://192.168.0.4:8084'
	myProps['headers'] = myHeaders
	myProps['body'] = '?action=stopServer&port=9000'
	Rho::Network.post(myProps, url_for(:action => :postEvent))  
  end
  
  def http_post_test_2
	puts "HTTP Post Test 2"
	myHeaders = Hash.new
	myHeaders['Content-Length'] = 19
	
	myProps = Hash.new
	myProps['url'] = 'http://192.168.0.4:8084'
	myProps['headers'] = myHeaders
	myProps['body'] = '?action=startServer'
	Rho::Network.post(myProps, url_for(:action => :postEvent))  
  end
  
  def connectWAN
	puts "Connecting to WAN"
	Rho::Network.connectWan(@params['connectionDestination'], url_for(:action => :wanConnectionMessage))
  end
  
  def disconnectWAN
	puts "Disconnecting from WAN"
	Rho::Network.disconnectWan
  end
  
  def wanConnectionMessage
	puts "Received WAN Connection Message #{@params}"
	WebView.execute_js("wanEvent('#{@params["phoneSignalStrength"]}', '#{@params["networkOperator"]}', '#{@params["connectionTypeAvailable"]}', '#{@params["connectionTypeConnected"]}', '#{@params["connectionManagerMessage"]}');")
  end
  
end
