//
//  FATBaseLoadFailedView.h
//  FinApplet
//
//  Created by luojian on 2021/11/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATBaseLoadFailedView : UIView

/**
 错误提示图片
 */
@property (nonatomic, strong) UIImageView *errorImageView;
/**
 错误标题
 */
@property (nonatomic, strong) UILabel *errorLabel;
/**
 错误详情
 */
@property (nonatomic, strong) UILabel *detailLabel;
/**
 重新加载按钮
 */
@property (nonatomic, strong) UIButton *reloadButton;

/**
 重新加载block
 */
@property (nonatomic, copy) dispatch_block_t reloadBlock;

@end

NS_ASSUME_NONNULL_END
