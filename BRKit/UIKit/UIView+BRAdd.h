//
//  UIView+BRAdd.h
//  BRKitDemo
//
//  Created by 任波 on 2018/5/2.
//  Copyright © 2018年 91renb. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BRDirectionType) {
    BRDirectionTypeLeftToRight = 0,
    BRDirectionTypeTopToBottom
};

/// 边框类型(位移枚举)
typedef NS_ENUM(NSInteger, BRBorderSideType) {
    BRBorderSideTypeAll    = 0,
    BRBorderSideTypeTop    = 1 << 0,
    BRBorderSideTypeBottom = 1 << 1,
    BRBorderSideTypeLeft   = 1 << 2,
    BRBorderSideTypeRight  = 1 << 3,
};

@interface UIView (BRAdd)
/** 返回视图的视图控制器(可能为nil) */
@property (nullable, nonatomic, readonly) UIViewController *viewController;
/** left: frame.origin.x */
@property (nonatomic) CGFloat left;
/** top: frame.origin.y */
@property (nonatomic) CGFloat top;
/** right: frame.origin.x + frame.size.width */
@property (nonatomic) CGFloat right;
/** bottom: frame.origin.y + frame.size.height */
@property (nonatomic) CGFloat bottom;
/** width: frame.size.width */
@property (nonatomic) CGFloat width;
/** height: frame.size.height */
@property (nonatomic) CGFloat height;
/** centerX: center.x */
@property (nonatomic) CGFloat centerX;
/** centerY: center.y */
@property (nonatomic) CGFloat centerY;
/** origin: frame.origin */
@property (nonatomic) CGPoint origin;
/** size: frame.size */
@property (nonatomic) CGSize  size;

/**
 *  设置视图view的部分圆角(绝对布局)
 *
 *  @param corners  需要设置为圆角的角(枚举类型)
 *  @param radius   需要设置的圆角大小
 */
- (void)br_setRoundedCorners:(UIRectCorner)corners
                  withRadius:(CGSize)radius;

/**
 *  设置视图view的部分圆角(相对布局)
 *
 *  @param corners  需要设置为圆角的角(枚举类型)
 *  @param radius   需要设置的圆角大小
 *  @param rect     需要设置的圆角view的rect
 */
- (void)br_setRoundedCorners:(UIRectCorner)corners
                  withRadius:(CGSize)radius
                    viewRect:(CGRect)rect;

/**
 *  设置视图view的阴影
 *
 *  @param color  阴影颜色
 *  @param offset 阴影偏移量
 *  @param radius 阴影半径
 */
- (void)br_setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius;

/** 删除所有子视图 */
- (void)br_removeAllSubviews;

/** 创建屏幕快照 */
- (nullable UIImage *)br_snapshotImage;

/** 创建屏幕快照pdf */
- (nullable NSData *)br_snapshotPDF;

/** 设置view的渐变色 */
- (void)br_setGradientColor:(UIColor *)fromColor toColor:(UIColor *)toColor direction:(BRDirectionType)direction;

/** 设置view的边框线（使用注意：1、先把view添加到父视图，再设置边框；2、可以设置多个边框：BRBorderSideTypeTop | BRBorderSideTypeBottom） */
- (void)br_setBorderType:(BRBorderSideType)borderType borderColor:(UIColor *)borderColor borderWidth:(CGFloat)borderWidth;

@end

NS_ASSUME_NONNULL_END
