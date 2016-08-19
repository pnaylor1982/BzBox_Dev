# BzBox_Dev


ThingSpeak Cloud - sensor reading stream:

	Place particle to build/connect to Particle API cloud.

		$particle config particle

	Compile locally (from project directory)

		$particle compile photon . --saveTo firmware_name.bin

	Place Photon in DFU mode (flashing orange)

		$particle flash --usb firmwarename.bin

	Go to ThingSpeak.com and view channel.  Also should see traffic on https://console.particle.io/logs

		$curl https://api.particle.io/v1/devices/events?access_token=53c7bd0ab1041f51a9c4063d34650e54975b6727

	More webhooks can be added through https://console.particle.io/integrations
	https://docs.particle.io/guide/tools-and-features/webhooks/
	https://www.hackster.io/makers-ns/particle-photon-thingspeak-e063d5
	https://www.hackster.io/15223/thingspeak-particle-photon-using-webhooks-dbd96c


Move Photon to local cloud:
	https://community.particle.io/t/tutorial-local-cloud-1st-time-instructions-01-oct-15/5589

	set Photon to local config (or set up config)

		$particle config local

	If 1st time... connect Photon to local cloud, run setup to create login credentials

		$particle setup

	set node version to v0.10

		$nvm use v0.10

	start spark-server:
	https://github.com/spark/spark-server

		$cd ~/spark-server
		$node main.js

	In DFU mode, flash local keys

		$particle keys server default_key.pub.pem YOUR_LOCAL_IP_ADDRESS

	If 1st time... save public key to core_key directory (in DFU mode)

		$cd core_keys
		$particle keys save INPUT_DEVICE_ID_HERE

	check particle connection

		$particle list


Live ADC Stream in html5 (Photon in local cloud):

	Load livegraph.cpp program onto Photon

	run node.js html server

		$cd ~/livegraph-master
		$node livegraph.js

	open web browswer to local server address, port 8080

		localhost:8080



Move Photon back to Particle.io cloud:

	set Photon to particle config

		$particle config particle

	change unit keys back to particle
	https://docs.particle.io/support/troubleshooting/key-management/core/
	https://s3.amazonaws.com/spark-website/cloud_public.der
		
		$particle keys server cloud_public.der

	Reset Photon (button)

	check particle connection:

		$particle list



Load program:

	Either flash from Atom IDE (cloud) or compile, load through USB in DFU mode:



New code branch in GIT:






