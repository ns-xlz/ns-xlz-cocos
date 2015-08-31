#include "ChooseLayer.h"
#include "AppDelegate.h"
#include "DialogLayer.h"
#include <string>
#include "AppMacros.h"

using namespace cocos2d;
using namespace std;

int ChooseLayer::modeLevel = 0;

//ʵ��ChooseLayer���е�init��������ʼ������
bool ChooseLayer::init()
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
	Sprite* bSprite = Sprite::create(choose_PATH+string("background.png"));
	//���þ�������λ��
	bSprite->setPosition(Point(400,240));
	//��������ӵ�������
	this->addChild(bSprite,BACKGROUND_LEVEL_CGQ);

	//�����ؿ�1�ľ���
	MenuItemImage *oneGuan = MenuItemImage::create
	(
		choose_PATH+string("guanka1.png"),		//ƽʱ��ͼƬ
		choose_PATH+string("guanka11.png"),		//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::oneMode, this)
	);
	//����λ��
	oneGuan->setPosition(Point(270,240));

	//�����ؿ�2�ľ���
	MenuItemImage *twoGuan = MenuItemImage::create
	(
		choose_PATH+string("guanka2.png"),		//ƽʱ��ͼƬ
		choose_PATH+string("guanka22.png"),		//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::twoMode, this)
	);
	twoGuan->setPosition(Point(370,240));

	//�����ؿ�3�ľ���
	MenuItemImage *threeGuan = MenuItemImage::create
	(
		choose_PATH+string("guanka3.png"),		//ƽʱ��ͼƬ
		choose_PATH+string("guanka33.png"),		//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::threeMode, this)
	);
	threeGuan->setPosition(Point(470,240));

	//�����ؿ�4�ľ���
	MenuItemImage *fourGuan = MenuItemImage::create
	(
		choose_PATH+string("guanka4.png"),     //ƽʱ��ͼƬ
		choose_PATH+string("guanka44.png"),   //ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::fourMode, this)
	);
	fourGuan->setPosition(Point(570,240));

	//�����ؿ�5�ľ���
	MenuItemImage *fiveGuan = MenuItemImage::create
	(
		choose_PATH+string("guanka5.png"),		//ƽʱ��ͼƬ
		choose_PATH+string("guanka55.png"),		//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::fiveMode, this)
	);
	//����λ��
	fiveGuan->setPosition(Point(670,240));

	//�������ذ�ť����
	MenuItemImage *fanHui = MenuItemImage::create
	(
		choose_PATH+string("fanhui.png"),		//ƽʱ��ͼƬ
		choose_PATH+string("fanhui.png"),		//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(ChooseLayer::sixMode, this)
	);
	//����λ��
	fanHui->setPosition(Point(750,420));

	//�����˵�����
	pMenu = Menu::create(oneGuan,twoGuan,threeGuan,fourGuan,fiveGuan,fanHui,NULL);
	//���ò˵�λ��
	pMenu->setPosition(Point(0,0));
	//���˵���ӵ�������
	this->addChild(pMenu,GAME_LEVEL_CGQ);

	return true;
}

void ChooseLayer::oneMode(Object* pSender)
{
	ChooseLayer::modeLevel = 0;
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//�ؿ�1��ͼ
	man->toGameLayer();
	if(DialogLayer::isMusic)
	{
		//���ű�������
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
		(
			"sound/bg_music.mp3",
			true
		);
	}
}
void ChooseLayer::twoMode(Object* pSender)
{
	ChooseLayer::modeLevel = 1;
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//�ؿ�2��ͼ
	man->toGameLayer();
	if(DialogLayer::isMusic)
	{
		//���ű�������
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
		(
			"sound/bg_music.mp3",
			true
		);
	}
}
void ChooseLayer::threeMode(Object* pSender)
{
	ChooseLayer::modeLevel = 2;
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//�ؿ�3��ͼ
	man->toGameLayer();
	if(DialogLayer::isMusic)
	{
		//���ű�������
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
		(
			"sound/bg_music.mp3",
			true
		);
	}
}
void ChooseLayer::fourMode(Object* pSender)
{
	ChooseLayer::modeLevel = 3;
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//�ؿ�4��ͼ
	man->toGameLayer();
	if(DialogLayer::isMusic)
	{
		//���ű�������
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
		(
			"sound/bg_music.mp3",
			true
		);
	}
}
void ChooseLayer::fiveMode(Object* pSender)
{
	ChooseLayer::modeLevel = 4;
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//�ؿ�5��ͼ
	man->toGameLayer();
	if(DialogLayer::isMusic)
	{
		//���ű�������
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
		(
			"sound/bg_music.mp3",
			true
		);
	}
}

void ChooseLayer::sixMode(Object* pSender)
{
	//����������
	man->toBeginLayer();
	//��Ӱ���ʱ����Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
}

