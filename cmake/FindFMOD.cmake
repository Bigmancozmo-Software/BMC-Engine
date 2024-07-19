# TODO: just put fmod in the source code lol

set(FMOD_API_DIRECTORY "")

if(WIN32)
	message("Using Windows")
	if(EXISTS "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/core/lib/x64/fmodL.dll")
		message("Found in default install directory")
		set(FMOD_API_DIRECTORY "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/core/lib/x64/fmodL.dll")
	else()
		message(FATAL_ERROR "Failed to find FMOD!" "\nC:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api")
	endif()
else()
# Assume Linux is being used, as the engine is not designed for Mac.
	message("Using Linux")
	message(FATAL_ERROR "Linux not implemented yet - sorry!")
endif()

message(${FMOD_API_DIRECTORY})
message("")
