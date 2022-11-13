#!/usr/bin/python3

import requests

url = 'http://wxa-50/YamahaRemoteControl/ctrl'

requests.post(url, '<YAMAHA_AV cmd="PUT"><Main_Zone><Power_Control><Power>On</Power></Power_Control></Main_Zone></YAMAHA_AV>')
requests.post(url, '<YAMAHA_AV cmd="PUT"><Main_Zone><Input><Input_Sel>USB</Input_Sel></Input></Main_Zone></YAMAHA_AV>')
requests.post(url, '<YAMAHA_AV cmd="PUT"><Main_Zone><Volume><Lvl><Val>-450</Val><Exp>1</Exp><Unit>dB</Unit></Lvl></Volume></Main_Zone></YAMAHA_AV>')
# it won't start playing until any song selected. this also starts playing
requests.post(url, '<YAMAHA_AV cmd="PUT"><USB><List_Control><Direct_Sel>Line_1</Direct_Sel></List_Control></USB></YAMAHA_AV>')
# shuffle
requests.post(url, '<YAMAHA_AV cmd="PUT"><USB><Play_Control><Play_Mode><Shuffle>On</Shuffle></Play_Mode></Play_Control></USB></YAMAHA_AV>')
# next song will be randomly due to shuffle
requests.post(url, '<YAMAHA_AV cmd="PUT"><USB><Play_Control><Playback>Skip Fwd</Playback></Play_Control></USB></YAMAHA_AV>')
