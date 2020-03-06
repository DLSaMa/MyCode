//
//  WUVerification.h
//  WUVerification
//
//  Created by WU on 2019/12/10.
//  Copyright © 2019 WU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 WULayoutConstraint 布局参照item

 - WULayoutItemNone: 不参照任何item。可用来直接设置width、height
 - WULayoutItemLogo:  参照logo视图
 - WULayoutItemNumber: 参照号码栏
 - WULayoutItemSlogan: 参照标语栏
 - WULayoutItemLogin: 参照登录按钮
 - WULayoutItemCheck: 参照隐私选择框
 - WULayoutItemPrivacy: 参照隐私栏
 - WULayoutItemSuper: 参照父视图
 */
typedef NS_ENUM(NSUInteger, WULayoutItem) {
    WULayoutItemNone = 1,
    WULayoutItemLogo,
    WULayoutItemNumber,
    WULayoutItemSlogan,
    WULayoutItemLogin,
    WULayoutItemCheck,
    WULayoutItemPrivacy,
    WULayoutItemSuper
};

@interface WULConstraint : NSObject

/**
 授权页布局类，使用Autolayout处理。用法参考系统类NSLayoutConstraint 以及示例demo。
 */
@property (nonatomic, assign) NSLayoutAttribute firstAttribute;
@property (nonatomic, assign) NSLayoutAttribute secondAttribute;
@property (nonatomic, assign) NSLayoutRelation relation;
@property (nonatomic, assign) WULayoutItem item;
@property (nonatomic, assign) CGFloat multiplier;
@property (nonatomic, assign) CGFloat constant;

/**
 相对父视图的布局约束

 @param attr1 约束类型
 @param relation 与参照视图之间的约束关系
 @param item 参照item
 @param attr2 参照item约束类型
 @param multiplier 乘数
 @param c 常量
 @return JVLayoutConstraint布局对象
 */
+(instancetype)constraintWithAttribute:(NSLayoutAttribute)attr1
                             relatedBy:(NSLayoutRelation)relation
                                toItem:(WULayoutItem)item
                             attribute:(NSLayoutAttribute)attr2
                            multiplier:(CGFloat)multiplier
                              constant:(CGFloat)c;

@end


@interface WUUIConfig : NSObject


#pragma mark =======导航栏设置========
/**导航栏颜色*/
@property (nonatomic,strong) UIColor *navColor;
/**授权页 preferred status bar style，取代barStyle参数 */
@property (nonatomic,assign) UIStatusBarStyle preferredStatusBarStyle;
/**协议页 preferred status bar style，取代barStyle参数 */
@property (nonatomic,assign) UIStatusBarStyle agreementPreferredStatusBarStyle;
/**导航栏标题*/
@property (nonatomic,copy) NSAttributedString *navText;
/**导航栏标题颜色*/
@property (nonatomic,strong) UIColor *navTextColor;
/**导航栏默认返回按钮隐藏，默认不隐藏*/
@property (nonatomic,assign) BOOL navReturnHidden;
/**导航返回按钮图标*/
@property (nonatomic,strong) UIImage *navReturnImg;
/*导航栏返回按钮图片缩进,默认为UIEdgeInsetsZero*/
@property (nonatomic,assign) UIEdgeInsets navReturnImageEdgeInsets;
/**导航栏右侧自定义控件*/
@property (nonatomic,strong) UIBarButtonItem *navControl;
/**是否隐藏导航栏（适配全屏图片）*/
@property (nonatomic,assign) BOOL navCustom;
/**导航栏是否透明，默认不透明。此参数和navBarBackGroundImage冲突，应避免同时使用*/
@property (nonatomic,assign) BOOL navTransparent;
/**导航栏背景图片.此参数和navTransparent冲突，应避免同时使用*/
@property (nonatomic,strong) UIImage *navBarBackGroundImage;
/**导航栏分割线是否隐藏，默认隐藏*/
@property (nonatomic,assign) BOOL navDividingLineHidden;

/**竖屏情况下，是否隐藏状态栏。默认NO
 在项目的Info.plist文件里设置UIViewControllerBasedStatusBarAppearance为YES
 注意：弹窗模式下无效，是否隐藏由外部控制器控制*/
@property (nonatomic,assign) BOOL prefersStatusBarHidden;



#pragma mark =======图片设置========
/**授权界面背景图片*/
@property (nonatomic,strong) UIImage *authPageBackgroundImage;
/**LOGO图片*/
@property (nonatomic,strong) UIImage *logoImg;
/**OGO图片布局*/
@property (nonatomic, copy) NSArray * logoConstraints;
/*LOGO图片 横屏布局，横屏时优先级高于logoConstraints*/
@property (nonatomic, copy) NSArray * logoHorizontalConstraints;
/**LOGO图片隐藏*/
@property (nonatomic,assign) BOOL logoHidden;




#pragma mark =======登陆按钮=======
/**登录按钮文本*/
@property (nonatomic,strong) NSString *logBtnText;
/**登录按钮字体，默认跟随系统*/
@property (nonatomic,strong) UIFont *logBtnFont;
/*登录按钮布局*/
@property (nonatomic, copy) NSArray * logBtnConstraints;
/*登录按钮 横屏布局，横屏时优先级高于logBtnConstraints*/
@property (nonatomic, copy) NSArray * logBtnHorizontalConstraints;
/**登录按钮文本颜色*/
@property (nonatomic,strong) UIColor *logBtnTextColor;
/**登录按钮背景图片添加到数组(顺序如下)
 @[激活状态的图片,失效状态的图片,高亮状态的图片]
 注意:当customPrivacyAlertViewBlock不为空，并且隐私栏为选中时，失效状态的图片设置无效
 */
@property (nonatomic,copy) NSArray *logBtnImgs;


#pragma mark =======号码框设置=======
/**手机号码字体颜色*/
@property (nonatomic,strong) UIColor *numberColor;
/**手机号码字体大小*/
@property (nonatomic,assign) CGFloat numberSize;
/*手机号码字体，优先级高于numberSize*/
@property (nonatomic,strong) UIFont *numberFont;
/*号码栏布局 宽高自适应，不需要设置*/
@property (nonatomic, copy) NSArray * numberConstraints;
/*号码栏 横屏布局,横屏时优先级高于numberConstraints*/
@property (nonatomic, copy) NSArray * numberHorizontalConstraints;





#pragma mark =======隐私条款=======
/*复选框是否隐藏，默认不隐藏*/
@property (nonatomic,assign) BOOL checkViewHidden;
/*复选框布局*/
@property (nonatomic, copy) NSArray * checkViewConstraints;
/*复选框 横屏布局，横屏优先级高于checkViewConstraints*/
@property (nonatomic, copy) NSArray * checkViewHorizontalConstraints;

/**隐私条款一:数组（务必按顺序）
 @[条款名称,条款链接]
 */
@property (nonatomic,strong) NSArray *appPrivacyOne;
/**隐私条款二:数组（务必按顺序）
 @[条款名称,条款链接]
 */
@property (nonatomic,strong) NSArray *appPrivacyTwo;
/**隐私条款名称颜色
 @[基础文字颜色,条款颜色]
 */
@property (nonatomic,strong) NSArray *appPrivacyColor;



/**隐私条款文本对齐方式，目前仅支持 left、center*/
@property (nonatomic,assign) NSTextAlignment privacyTextAlignment;
/**隐私条款字体大小，默认12*/
@property (nonatomic,assign) CGFloat privacyTextFontSize;
/**隐私条款行距，默认跟随系统*/
@property (nonatomic,assign) CGFloat privacyLineSpacing;

/**隐私条款拼接文本数组，数组限制4个NSString对象，否则无效
 默认
 文本1为：”登录即同意“
 文本2:”和“
 文本3：”、“
 文本4：”并使用本机号码进行验证“
 设置后，隐私协议栏文本修改为 文本1 + 运营商默认协议名称 + 文本2 + 开发者协议名称1 + 文本3 + 开发者协议文本2 + 文本4
 */
@property (nonatomic,strong) NSArray <NSString *>* privacyComponents;
/*隐私条款布局*/
@property (nonatomic, copy) NSArray * privacyConstraints;
/*隐私条款 横屏布局，横屏下优先级高于privacyConstraints*/
@property (nonatomic, copy) NSArray * privacyHorizontalConstraints;
/**隐私条款check框默认状态 默认:NO */
@property (nonatomic,assign) BOOL privacyState;
/*
 当自定义Alert view,当隐私条款未选中时,点击登录按钮时回调
 当此参数存在时,未选中隐私条款的情况下，登录按钮可以被点击
 block内部参数为自定义Alert view可被添加的控制器，详细用法可参见示例demo
 注意：当此参数不为空并且隐私栏为选中的情况下，logBtnImgs失效状态图片设置无效
 */
@property (nonatomic,copy) void(^WuCustomPrivacyAlertViewBlock)(UIViewController * vc);


#pragma mark =======slogan=======
/*slogan布局，宽高自适应不需要设置*/
@property (nonatomic, copy) NSArray * sloganConstraints;
/*slogan 横屏布局,横屏下优先级高于sloganConstraints*/
@property (nonatomic, copy) NSArray * sloganHorizontalConstraints;
/**slogan文字颜色*/
@property (nonatomic,strong) UIColor *sloganTextColor;
/*slogan文字font,默认12*/
@property (nonatomic,strong) UIFont *sloganFont;

/*自定义loading view,当授权页点击登录按钮时回调
 当此参数存在时,默认loading view不会显示,需开发者自行设计loading view
 block内部参数为自定义loading view可被添加的父视图，详细用法可参见示例demo
 */
@property (nonatomic,copy) void(^WuCustomLoadingViewBlock)(UIView * View);


#pragma mark =======弹窗样式设置=======
/*是否弹窗，默认no*/
@property (nonatomic, assign) BOOL showWindow;
/*弹框内部背景图片*/
@property (nonatomic, strong) UIImage *windowBackgroundImage;
/*弹窗外侧 透明度  0~1.0*/
@property (nonatomic, assign) CGFloat windowBackgroundAlpha;
/*弹窗圆角数值*/
@property (nonatomic, assign) CGFloat windowCornerRadius;
/*弹窗布局*/
@property (nonatomic, copy) NSArray * windowConstraints;

/*弹窗横屏布局，横屏下优先级高于windowConstraints*/
@property (nonatomic, copy) NSArray * windowHorizontalConstraints;

/*弹窗close按钮图片 @[普通状态图片，高亮状态图片]*/
@property (nonatomic, copy) NSArray <UIImage *>*windowCloseBtnImgs;
/*弹窗close按钮布局*/
@property (nonatomic, copy) NSArray * windowCloseBtnConstraints;
/*弹窗close按钮 横屏布局,横屏下优先级高于windowCloseBtnConstraints */
@property (nonatomic, copy) NSArray * windowCloseBtnHorizontalConstraints;



/*是否支持自动旋转 默认YES。
 注意: 当授权页为弹框样式时,参数无效，是否旋转由当前视图控制器控制 */
@property (nonatomic,assign) BOOL  shouldAutorotate;
/*设置进入授权页的屏幕方向。不支持UIInterfaceOrientationPortraitUpsideDown
 注意:当授权页为弹框样式时,参数无效，屏幕方向由当前视图控制器控制 */
@property (nonatomic, assign) UIInterfaceOrientation orientation;

/**协议页导航栏背景颜色*/
@property (nonatomic, strong) UIColor *agreementNavBackgroundColor;
/*授权页点击运营商默认协议，进入协议页时, 协议页自定义导航栏标题*/
@property (nonatomic, strong) NSAttributedString *agreementNavText;
/*授权页点击自定义协议1，进入协议页时, 协议页自定义导航栏标题*/
@property (nonatomic, strong) NSAttributedString *firstPrivacyAgreementNavText;
/*授权页点击自定义协议2，进入协议页时, 协议页自定义导航栏标题*/
@property (nonatomic, strong) NSAttributedString *secondPrivacyAgreementNavText;
/*协议页导航栏返回按钮图片*/
@property (nonatomic, strong) UIImage *agreementNavReturnImage;

/**授权页弹出方式,
 弹窗模式下不支持 UIModalTransitionStylePartialCurl*/
@property (nonatomic,assign) UIModalTransitionStyle  modalTransitionStyle;

/*关闭授权页是否有动画。默认YES,有动画。参数仅作用于以下两种情况：
 1、一键登录接口设置登录完成后，自动关闭授权页
 2、用户点击授权页关闭按钮，关闭授权页
 */
@property (nonatomic, assign) BOOL dismissAnimationFlag;




@end



typedef void(^resultBlock)(NSDictionary *resultDic);




@interface WUVerification : NSObject

+(instancetype)shareWU;


#pragma mark ====配置相关API====


/**
 *  初始化SDK
 *
 @param appid 由sdk sever分配，每个合作伙伴的每 个应用分配独立的 appid
 @param secret 由sdk sever分配，每个合作伙伴的每 个应用分配独立的 secret
 *
 */
+(void)wuVerInitWithAppid:(NSString *)appid secret:(NSString *)secret;


/**
  是否需要idfa
@param need 是否要
 */
+(void)wuSetAdvertisingId:(BOOL)need;

/**
  是否需要开启debug
@param enable 是否要
 */
+(void)wuSetDebug:(BOOL)enable;
/**
   清理缓存
 */
+(void)wuClearCache;
/**
  检测网络环境是否支持
*/
+ (BOOL)wuCheckNetEnable;
/**
  检测SDK是都初始化成功
 */
+(BOOL)wuCheckUpSDK;


#pragma mark ====授权相关API====

/**
 *  手机号校验token
 @param result token相关信息。
 */
+(void)wuGetToken:(resultBlock)result;

/**
 *  手机号校验token
 @param result token相关信息。
 */
+(void)wuGetToken:(NSTimeInterval)timeout result:(resultBlock)result;

/**
 获取accessCode
 @param timeout 超时时间
 @param result 预取号相关信息。
 
 */
+(void)wuGetAccessCode:(NSTimeInterval)timeout result:(resultBlock)result;

/**
 预取号
 @param timeout 超时时间
 @param result 预取号相关信息
 */
+(void)wuPreLogin:(NSTimeInterval)timeout result:(resultBlock)result;


//手机号验证的
+(void)wuNumberCheck:(NSTimeInterval)timeout result:(void(^)(NSDictionary *resultDic))result;
//+(void)wuverifyGetToken:(NSTimeInterval)timeout result:(void(^)(NSDictionary *resultDic))result;


#pragma mark ====窗口相关API====
/**
  一键登录
@param timeout 超时时间
@param vc   显示指示页面的控制器
@param result 一键登录的结果
 */
+(void)wuLogin:(NSTimeInterval)timeout showController:(UIViewController *)vc result:(resultBlock)result;

+(void)dismissLoginControllerAnimated: (BOOL)flag;


#pragma mark ====自定义====
/**
 自定义登录页UI样式参数
 @param UIConfig  UIConfig对象实例。仅使用JVUIConfig类型对象
 @param customViews 添加自定义视图block
*/
+ (void)wuCustomUIWithConfig:(WUUIConfig *)UIConfig customViews:(void(^)(UIView *customAreaView))customViews;




@end
