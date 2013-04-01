require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'
#require 'barcode'

class BarcodeTestController < Rho::RhoController
  include BrowserHelper
  include ApplicationHelper
  
  def test_proc(arg)
    puts "test_proc : #{arg}"
  end
  
  #@@test_proc = lambda{|args| puts "lamda: #{args}"}
  def index
	render :back => '/app/BarcodeTest'
  end

  def test_callback
    puts "test_callback: #{@params}"
  end
  
  def dcTest_cb
	WebView.execute_js("outputMsg('Hello Darryn');")
  end
  
  def decodeEvent
	puts "Scanned Barcode #{@params}"
	decodeHash = @params
	puts "Data is #{decodeHash['data']}"
	WebView.execute_js("onDecodeEventRuby('#{decodeHash['data']}','#{decodeHash['source']}','#{decodeHash['type']}','#{decodeHash['time']}','#{decodeHash['length']}','Decode','#{decodeHash['direction']}');")
  end
  
  def takeEvent
	puts "Take Barcode #{@params}"
	decodeHash = @params
	puts "Data is #{decodeHash['barcode']}"
	WebView.execute_js("outputMsg('#{decodeHash['barcode']}  #{decodeHash['status']}');")
  end
  
  def bluetoothStatus
	puts "Bluetooth Status #{@params}"
	decodeHash = @params
	puts "Data is #{decodeHash['status']}"
	WebView.execute_js("outputMsg('#{decodeHash['status']}');")
  end
  
  def enumerateScanners
	WebView.execute_js("clearScannerEnumeration();")
	arBarcodes = Rho::Barcode.enumerate
	arBarcodes.each {|x| WebView.execute_js("addScannerToEnumeration('" + x.getProperty('ID') + "');")}
	arBarcodes.each {|x| puts x.getProperty('ID') }
#	Rho::Barcode.enumerate(lambda{args.each|args| WebView.execute_js("addScannerToEnumeration(" + args.getProperty('ID') + ");")} )
  end
  
  def receiveValues
	puts "Received Values #{@params}"
	WebView.execute_js("outputMsg('Received a Value #{@params[0]}');")
#	lambda{|args| puts "AllProps: #{args}"}
  end
  
  def retrieveValues
	Rho::Barcode.getAllProperties(url_for(:action => :receiveValues) )
#	puts Rho::Barcode.illuminationMode
  end
  
  def setDefaultScanner
	#Rho::Barcode.setDefault("#{@params['specifiedScanner']}")
	arBarcodes = Rho::Barcode.enumerate
	arBarcodes.each {|x| if @params['specifiedScanner'] == x.getProperty('ID') then Rho::Barcode.setDefault(x) end}
  end

  def callBarcodeMethod
	puts "Scanner Method / Property Called #{@params}"
	theMethod = @params['method']
	puts "The Method: #{theMethod}"
	puts "The Params: #{@params['dccParams']}"
	if theMethod == "enable"
#		Rho::Barcode.enable(@params['dccParams'], "/app/BarcodeTest/decodeEvent")
		Rho::Barcode.enable(@params['dccParams'], url_for(:action => :decodeEvent))
	elsif theMethod == "start"
		Rho::Barcode.start
	elsif theMethod == "stop"
		Rho::Barcode.stop
	elsif theMethod == "disable"
		Rho::Barcode.disable
	elsif theMethod == "take"
		Rho::Barcode.take(@params['dccParams'], url_for(:action => :takeEvent))
	elsif theMethod == "registerBluetoothStatus"
		Rho::Barcode.registerBluetoothStatus(url_for(:action => :bluetoothStatus))
	elsif theMethod == "enableNoCallback"
		Rho::Barcode.enable
	elsif theMethod == "commandRemoteScanner"
		Rho::Barcode.commandRemoteScanner(@params['dccParams'])
	end
  end
  
  def setBarcodeProperties
	puts "Setting Scanner Property #{@params}"
	myProps = Hash.new
	myProps[@params['name']] = @params['value']
	Rho::Barcode.setProperties(myProps)
  end
  
  def getBarcodeProperty
	puts "Getting Barcode Property #{@params}"
	#myValue = "hats"
	myValue = Rho::Barcode.getProperty(@params['name'])
	puts "Retrieved Value: #{myValue}"
	render :json => myValue
	return myValue
  end
  
  def setRSMProperty
	puts "Setting RSM Property #{@params}"
	myProps = Hash.new
	myProps[@params['attribute']] = @params['valueToSet']
	Rho::Barcode.setProperty(myProps)
  end
  
  def getRSMProperty
	puts "Retrieving RSM Property #{@params}"
	myValue = Rho::Barcode.getProperty(@params['attribute'])
	puts "Received RSM Value: #{myValue}"
  end
  
  def getSupportedProperties
	puts "Getting Supported Properties"
	myProps = Rho::Barcode.getSupportedProperties
	puts "Supported Properties :#{myProps}"
  end
  
  def recognize
	puts "Recognizing... bad things will happen"
	myString = Rho::Barcode.recognize('/path/file.tif')
  end
  
  
  
  
  
  
  
  
  
  
  
  def run_test
    my_test = "123"
    Rho::Barcode.getProperty("display", lambda{|args| puts "lamda: #{args} #{my_test}"} )
    Rho::Barcode.getProperty("display", method(:test_proc) )
    Rho::Barcode.getProperty("display", Proc.new{|args| puts "proc: #{args}"} )
	displayProp = Rho::Barcode.getProperty("display")
	puts "dcc Display Prop: #{displayProp}"
    Rho::Barcode.enumerate(lambda{|args| puts "enum: #{args} #{my_test}"} )
    Rho::Barcode.getAllProperties(lambda{|args| puts "AllProps: #{args}"} )
    
#=begin
    Rho::Barcode.getProperty("display", "/app/BarcodeTest/test_callback")
    
    Rho::Barcode.getProperty("display", "/app/BarcodeTest/test_callback")
	Rho::Barcode.enable
    
    arBarcodes = Rho::Barcode.enumerate
    puts "arBarcodes : #{arBarcodes}"
	arBarcodes.each {|x| puts x.getProperty("ID")}
	
    id = arBarcodes[0].getProperty("ID")
    puts "id: #{id}"
    arBarcodes[1].getProperty("sound", "/app/BarcodeTest/test_callback")
    
    arBarcodes[1].getAllProperties( "/app/BarcodeTest/test_callback", "param1=123")

    #hash = { name: "David", age: 49 }
#    Rho::Barcode.setProperties(Barcode128:'enabled' )
    Rho::Barcode.setProperty("Barcode128", "enabled")
    arBarcodes[1].getProperty("Barcode128", "/app/BarcodeTest/test_callback")
    arBarcodes[0].getProperty("Barcode128", "/app/BarcodeTest/test_callback")
	WebView.execute_js("test(output1, 'Hello Darryn');");
#=end  
    render :action => :index
  end
  
end
