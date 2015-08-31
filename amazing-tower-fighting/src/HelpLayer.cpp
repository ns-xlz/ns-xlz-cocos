#include "AppDelegate.h"
#include "HelpLayer.h"
#include "AppMacros.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

//ʵ��HelpLayer���е�init��������ʼ������
bool HelpLayer::init()
{
    //���ø���ĳ�ʼ��
    if ( !Layer::init() )
    {
        return false;
    }

    //��ȡ�ɼ�����ߴ�
    Size visibleSize = Director::sharedDirector()->getVisibleSize();
    //��ȡ�ɼ�����ԭ������
    Point origin = Director::sharedDirector()->getVisibleOrigin();

	//������Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect
	(
		"sound/sf_button_press.mp3"
	);

    //����һ��������󣬰�������ͼƬ
    Sprite* backSprite = Sprite::create(help_PATH+string("backgroundh.png"));
    //���þ�������λ��
    backSprite->setPosition(Point(400,240));
	//��������ӵ�������
	this->addChild(backSprite,BACKGROUND_LEVEL_CGQ);

	//��������һ������ͼƬ������
	MenuItemImage *leftItem = MenuItemImage::create
	(
		help_PATH+string("left_up.png"),
		help_PATH+string("left_down.png"),
		CC_CALLBACK_1(HelpLayer::menuCallBack0, this)
	);
	leftItem->setScale(1.5);
	//���þ���˵���ť��λ��
	leftItem->setPosition(Point(330,450));

	//��������һ������ͼƬ������
	MenuItemImage *rightItem = MenuItemImage::create
	(
		help_PATH+string("right_up.png"),
		help_PATH+string("right_down.png"),
		CC_CALLBACK_1(HelpLayer::menuCallBack1, this)
	);
	rightItem->setScale(1.5);
	//���þ���˵���ť��λ��.
	rightItem->setPosition(Point(330,30));

	//���������ء�����
	MenuItemImage *fanhuiItem = MenuItemImage::create
	(
		help_PATH+string("fanhui.png"),
		help_PATH+string("fanhui.png"),
		CC_CALLBACK_1(HelpLayer::menuCallBack2, this)
	);
	//���þ���˵���ť��λ��.
	fanhuiItem->setPosition(Point(40,420));

	pMenu = Menu::create(leftItem,rightItem,fanhuiItem,NULL);
	//���ò˵���λ��
	pMenu->setPosition(Point(0,0));
	//���˵���ӵ�������
	this->addChild(pMenu,GAME_LEVEL_CGQ);
	initIntroPic();
    return true;
}
void HelpLayer::initIntroPic()
{
	for(int i = 0;i<9;i++)
	{
		//ͨ��createHelp��ȡ��ӦͼƬ��·��
		help[i] = Sprite::create(StringUtils::format("help/help%d.png",i));
		help[i]->setPosition(Point(440,245+i*480));
		this->addChild(help[i],GAME_LEVEL_CGQ);
	}
}

//���Ҽ�ͷ
void HelpLayer::menuCallBack0(Object* pSende)
{
	//���ű�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"sound/sf_button_press.mp3"
	);
	for(int i= 0 ;i<9;i++)
	{
		help[i] ->setPosition(Point(400,-480));
	}
	currPicIndex ++;
	if(currPicIndex == 9)
	{
		currPicIndex = 0;
	}
	help[currPicIndex%9] ->setPosition(Point(440,245));
}

//�����ͷ
void HelpLayer::menuCallBack1(Object* pSende)
{
	//���ű�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"sound/sf_button_press.mp3"
	);
	for(int i= 0 ;i<9;i++)
	{
		help[i] ->setPosition(Point(400,-480));
	}
	currPicIndex --;
	if(currPicIndex == -1)
	{
		currPicIndex = 8;
	}
	help[currPicIndex%9] ->setPosition(Point(440,245));
}

//�����ͷ
void HelpLayer::menuCallBack2(Object* pSende)
{
	//������Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//����������
	man->toBeginLayer();
}

