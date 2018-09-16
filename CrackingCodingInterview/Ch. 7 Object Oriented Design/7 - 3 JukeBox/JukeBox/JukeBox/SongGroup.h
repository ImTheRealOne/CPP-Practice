#pragma once
#include "SongComponent.h"
#include "Song.h"
#include <random>
#include <time.h>

#include "SongComponentVisitor.h"

class SongGroup : public SongComponent
{
public:
	SongGroup();
	SongGroup(std::string newGroupName, std::string newGroupDescription) :
		groupName(newGroupName), groupDescription(newGroupDescription) {};
	~SongGroup();

	std::string getGroupName() { return groupName; }
	std::string getGroupDescription(){ return groupDescription; }
	//note : cannot pass a abstract class by value
	//		but you can pass by reference
	void add(SongComponent* newSongComponent) {
		songList.push_back(newSongComponent);
	}
	void remove(SongComponent* newSongComponent) {
		songList.push_back(newSongComponent);
	}
	//note: cannot return an instance of an abstract class 
	//		but you can return a reference or pointer
	SongComponent* getComponentIndex(const int index) {
		return songList.at(index);
	}

	SongComponent* getCompositeIndex(SongComponent* currComponent, int songGroupIndex, int songIndex) {
		SongComponent* tempSongComponent;
		if (currComponent->getComposite()) {
			tempSongComponent = getCompositeIndex( static_cast<SongGroup*>(currComponent)->getComponentIndex(songGroupIndex), songGroupIndex, songIndex);
		}
		else
		{
			tempSongComponent = currComponent;
		}
		return tempSongComponent;
	}

	const std::vector<SongComponent* > &getSongList()  {
		return songList;
	}

	SongComponent* getComposite() { return this;}
	

	SongComponent* getRandomSong() {
		srand(time(NULL));
		int list = rand() % songList.size();
		if (songList.at(list)->getComposite()) {
			std::cout << "this is a song group" << std::endl;
		}
		else
		{
			std::cout << "this is a song" << std::endl;
		}
	


		return songList.at(list);
	}

	void displaySongInfo() {
		std::cout << "Group Name : " << groupName << std::endl;
		std::cout << "Group Descriptikon : " << groupDescription << std::endl;
		for (SongComponent* songs : songList) {
			songs->displaySongInfo();
		}
		std::cout << std::endl;
	}

	void displayPlayListInfo(SongComponent* currComponent, int songGroupIndex, int songIndex) {
		SongGroup* songGroupPtr = static_cast<SongGroup*>(currComponent);
		for (int i = 0; i < songGroupPtr->getSongList().size(); i++) {

			for (int j = 0; j < static_cast<SongGroup*>(songGroupPtr->getSongList().at(i))->getSongList().size(); j++) {
				std::cout << "Song Group : " << i << "  Track : " << j << std::endl;
				static_cast<SongGroup*>(songGroupPtr->getSongList().at(i))->getSongList().at(j)->displaySongInfo();
				std::cout << std::endl;
			}
			
		}
	
	}

	void Accept(SongComponentVisitor& visitor) {
		visitor.VisitSongGroup(this);
	}


private:
	std::vector<SongComponent* > songList;
	std::string groupName;
	std::string groupDescription;
};

