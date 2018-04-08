//
//  XHDatePickerView.h
//  XHDatePicker
//
//  Created by XH_J on 2016/10/25.
//  Copyright © 2016年 XHJCoder. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NSDate+XHExtension.h"

typedef enum{
    DateStyleShowYearMonthDayHourMinute  = 0,
    DateStyleShowMonthDayHourMinute,
    DateStyleShowYearMonthDay,
    DateStyleShowMonthDay,
    DateStyleShowHourMinute,
    DateStyleOnlyYearMonth
    
}XHDateStyle;

typedef enum{
    DateTypeStartDate,
    DateTypeEndDate
    
}XHDateType;

@interface XHDatePickerView : UIView

@property (nonatomic,assign)XHDateStyle datePickerStyle;
@property (nonatomic,assign)XHDateType dateType;
@property (nonatomic,strong)UIColor *themeColor;

@property (nonatomic, retain) NSDate *maxLimitDate;//限制最大时间（没有设置默认2049）
@property (nonatomic, retain) NSDate *minLimitDate;//限制最小时间（没有设置默认1970）

-(instancetype)initWithCompleteBlock:(void(^)(NSDate *,NSDate *))completeBlock;

/**
 *   设置打开选择器时的默认时间，
 *   minLimitDate < currentDate < maxLimitDate  显示 currentDate;
 *   currentDate < minLimitDate ||  currentDate > maxLimitDate   显示minLimitDate;
 */
-(instancetype)initWithCurrentDate:(NSDate *)currentDate CompleteBlock:(void(^)(NSDate *,NSDate *))completeBlock;


/**
 设置打开选择器时的默认时间，

 @param currentDate minLimitDate < currentDate < maxLimitDate  显示 currentDate;
 @param titleStr 时间选择器的标题要设置成什么
 @param completeBlock 选择的时间Block
 @return 时间选择器
 */
-(instancetype)initWithCurrentDate:(NSDate *)currentDate WithTitleStr:(NSString *)titleStr CompleteBlock:(void(^)(NSDate *,NSDate *))completeBlock;

-(void)show;


@end
