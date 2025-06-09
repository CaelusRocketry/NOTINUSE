import obspython as obs
import os
import random
import cv2


def generate_song_list(directory):
    music = []
    for file in os.listdir(directory):
        if file.endswith(".mp3"):
            music.append(os.path.join(directory, file))
    random.shuffle(music)
    return music

def generate_video_list(directory):
    videos = []
    for file in os.listdir(directory):
        if file.endswith(".mov"):
            direct = os.path.join(directory, file)
            video = cv2.VideoCapture(direct)
            duration = video.get(cv2.CAP_PROP_POS_MSEC)
            videos.append((direct, duration))
      
    random.shuffle(videos)
    return videos

def script_properties():
	props = obs.obs_properties_create()

	obs.obs_properties_add_text(props, "dir", "Folder Directory", obs.OBS_TEXT_DEFAULT)

	p = obs.obs_properties_add_list(props, "source", "Text Source", obs.OBS_COMBO_TYPE_EDITABLE, obs.OBS_COMBO_FORMAT_STRING)
	sources = obs.obs_enum_sources()
	if sources is not None:
		for source in sources:
			source_id = obs.obs_source_get_id(source)
			if source_id == "text_gdiplus" or source_id == "text_ft2_source":
				name = obs.obs_source_get_name(source)
				obs.obs_property_list_add_string(p, name, name)

		obs.source_list_release(sources)

	obs.obs_properties_add_button(props, "button", "Refresh", refresh_pressed)
	return props