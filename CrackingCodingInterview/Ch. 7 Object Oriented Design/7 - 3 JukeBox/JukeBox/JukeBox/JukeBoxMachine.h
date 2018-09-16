#pragma once

#include "SongGroup.h"

class JukeBoxMachine
{
public:
	JukeBoxMachine();
	JukeBoxMachine(SongGroup* newPlaylist) : playlist(newPlaylist) {};
	~JukeBoxMachine();

	void playSong(const int listIndex, const int songIndex) {
		SongComponent* tempSongComponentPtr;

		tempSongComponentPtr = playlist->getCompositeIndex(playlist->getComponentIndex(listIndex), listIndex, songIndex);
		std::cout << "NOW PLAYING : " << std::endl;
		tempSongComponentPtr->displaySongInfo();
	}

	void showPlaylist() {
		//playlist->displaySongInfo();
		playlist->displayPlayListInfo(playlist, 0, 0);
	}
private:
	SongGroup * playlist;	
};

