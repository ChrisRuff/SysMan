SysMan Layout:  
![Layout](docs/SysMan_Audio.png)

# Description
## Audio Devices
As can be seen, in the top panel there are the available audio devices that can be switched to by clicking on the device. This sets the device to the default sink.

In the lower frame microphones can be seen in the inputs list view, and application sources in the outputs list view. Multiple elements from each list can be selected by holding shift. The three buttons function as follows:

* Make Output: Takes all selected elements in the list views and creates sinks to stream them in addition to the microphone output
* Reset: Removes all sinks and returns the system back to the state before changed by SysMan
* Refresh: Updates items in the Inputs, Outputs, and the available audio sources.

### Map of Sinks generated
![Sinks_Layout](docs/Sink_Layout.png)

# Build instructions
To build the project:  
`git clone https://github.com/ChrisRuff/SysMan.git`  
`cd SysMan`
`cmake -Bbuild`  
`cd build && make`  
`./SysMan`  



# Example
![Example](docs/Ex.png)
In this example the audio output of the HyperX microphone is combined with the audio from Google Chrome and Spotify, while Zoom audio is directed to the Sysman audio channel to be sent to my headphones(Microphone doesn't pick up this audio)

**TO BE CLEAR**:  
* Sysman-Audio is sent to YOUR headphones alone
* Sysman-Apps is sent to your headphones AS WELL AS your microphone
* Sysman-(Apps+Mic) replaces your microphone as it has the apps included in the audio
