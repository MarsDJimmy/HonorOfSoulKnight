/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MENU.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MENU::createScene()
{
    return MENU::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MENU::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	auto NEWGAME_button1 = Sprite::create("NEWGAME_button1.png");
	auto NEWGAME_button2 = Sprite::create("NEWGAME_button2.png");
	auto MULTIPLAYERGAME_button1 = Sprite::create("MULTIPLAYERGAME_button1.png");
	auto MULTIPLAYERGAME_button2 = Sprite::create("MULTIPLAYERGAME_button2.png");
	auto QUIT_button1 = Sprite::create("QUIT_button1.png");
	auto QUIT_button2 = Sprite::create("QUIT_button2.png");

	auto NEWGAME_button = MenuItemSprite::create(
		NEWGAME_button1,
		NEWGAME_button2,
		CC_CALLBACK_1(MENU::menuCloseCallback, this));

	auto MULTIPLAYERGAME_button = MenuItemSprite::create(
		MULTIPLAYERGAME_button1,
		MULTIPLAYERGAME_button2,
		CC_CALLBACK_1(MENU::menuCloseCallback, this));

	auto QUIT_button = MenuItemSprite::create(
		QUIT_button1,
		QUIT_button2,
		CC_CALLBACK_1(MENU::menuCloseCallback, this));


 /*   if (QUIT_button == nullptr ||
		QUIT_button->getContentSize().width <= 0 ||
		QUIT_button->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - QUIT_button->getContentSize().width/2;
        float y = origin.y + QUIT_button->getContentSize().height/2;
		QUIT_button->setPosition(Vec2(x,y));
    }
*/
	auto menu = Menu::create(NEWGAME_button, MULTIPLAYERGAME_button, QUIT_button, NULL);
	menu->alignItemsVertically();
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(menu, 1);


    auto title1 = Label::createWithTTF("Honor of", "fonts/Marker Felt.ttf", 35);
    if (title1 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
		title1->setAnchorPoint(Point(1, 1));
		title1->setScale((visibleSize.width / title1->getContentSize().width) / 4);
		title1->setPosition(Vec2(origin.x + (visibleSize.width / 2),
			origin.y + visibleSize.height - title1->getContentSize().height));
        this->addChild(title1, 2);
    }


	auto title2 = Sprite::create("title2.jpg");
	if (title2 == nullptr)
	{
		problemLoading("'title2.jpg'");
	}
	else
	{
		title2->setScale((visibleSize.width / title2->getContentSize().width) / 3 * 1.3);
		title2->setAnchorPoint(Point(0.3, 0.5));
		title2->setPosition(Vec2(origin.x + (visibleSize.width / 2),
			origin.y + visibleSize.height - title2->getContentSize().height));
		this->addChild(title2, 1);
	}

	auto menu_pic = Sprite::create("timg.jpg");
	if (menu_pic == nullptr)
	{
		problemLoading("'timg.jpg'");
	}
	else
	{
		menu_pic->setScale((visibleSize.width / menu_pic->getContentSize().width) / 2);
		menu_pic->setAnchorPoint(Point(1, 0));
		menu_pic->setPosition(Vec2(visibleSize.width + origin.x, 0));
		this->addChild(menu_pic, 0);
	}
	return true;
}



void MENU::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
