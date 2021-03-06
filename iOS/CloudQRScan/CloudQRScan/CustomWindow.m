//
//  CustomWindow.m
//
//
//  Created by Jimmy Jose (jimmy@varshyl.com) on 15/01/14.
//  Copyright (c) 2014 Varshyl Mobile Pvt. Ltd. All rights reserved.
//

#import "CustomWindow.h"

@implementation CustomWindow

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}


- (void)tapAndHoldAction:(NSTimer*)timer {
    contextualMenuTimer = nil;
    UIView* clickedView = [self hitTest:CGPointMake(tapLocation.x, tapLocation.y) withEvent:nil];
    while (clickedView != nil) {
        if ([clickedView isKindOfClass:[UIWebView class]]) {
            break;
        }
        clickedView = clickedView.superview;
    }
    
    if (clickedView) {
        NSDictionary *coord = [NSDictionary dictionaryWithObjectsAndKeys:
                               [NSNumber numberWithFloat:tapLocation.x],@"x",
                               [NSNumber numberWithFloat:tapLocation.y],@"y",nil];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"TapAndHoldNotification" object:coord];
    }
}
- (void)tapAndHoldActionShort:(NSTimer*)timer {
    UIView* clickedView = [self hitTest:CGPointMake(tapLocation.x, tapLocation.y) withEvent:nil];
    while (clickedView != nil) {
        if ([clickedView isKindOfClass:[UIWebView class]]) {
            break;
        }
        clickedView = clickedView.superview;
    }
    
    if (clickedView) {
        NSDictionary *coord = [NSDictionary dictionaryWithObjectsAndKeys:
                               [NSNumber numberWithFloat:tapLocation.x],@"x",
                               [NSNumber numberWithFloat:tapLocation.y],@"y",nil];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"TapAndHoldShortNotification" object:coord];
    }
}

- (void)sendEvent:(UIEvent *)event {
    NSSet *touches = [event touchesForWindow:self];
    
    [super sendEvent:event];    // Call super to make sure the event is processed as usual
    
    if ([touches count] == 1) { // We're only interested in one-finger events
        UITouch *touch = [touches anyObject];
        
        switch ([touch phase]) {
             
            case UITouchPhaseStationary:
                
            case UITouchPhaseBegan: { // A finger touched the screen
                tapLocation = [touch locationInView:self];
                [contextualMenuTimer invalidate];
                contextualMenuTimer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(tapAndHoldAction:) userInfo:nil repeats:NO];
                NSTimer *myTimer;
                myTimer = [NSTimer scheduledTimerWithTimeInterval:0.2 target:self selector:@selector(tapAndHoldActionShort:) userInfo:nil repeats:NO];
                break;}
                
            case UITouchPhaseEnded:
            case UITouchPhaseMoved:
            case UITouchPhaseCancelled:
                [contextualMenuTimer invalidate];
                contextualMenuTimer = nil;
                break;
        }
    } else {        // Multiple fingers are touching the screen
        [contextualMenuTimer invalidate];
        contextualMenuTimer = nil;
    }
    
}


/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
