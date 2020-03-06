//
//  XDXVPNManager.m
//  XDXRouterDemo
//
//  Created by 小东邪 on 30/03/2018.
//  Copyright © 2018 小东邪. All rights reserved.
//

#import  "XDXVPNManager.h"
#import  <NetworkExtension/NetworkExtension.h>
#import  "XDXVPNManagerModel.h"
#import  "NSMutableDictionary+XDXSafeSetRemove.h"


@interface XDXVPNManager()

@property (nonatomic, strong) XDXVPNManagerModel *vpnConfigurationModel;

@end

@implementation XDXVPNManager

#pragma mark - Init
- (instancetype)init {
    if (self = [super init]) {
        self.vpnManager             = [[NETunnelProviderManager alloc] init];
        self.vpnConfigurationModel  = [[XDXVPNManagerModel alloc] init];
    }
    return self;
}

#pragma mark - Main Func Public
- (void)configManagerWithModel:(XDXVPNManagerModel *)model {
    self.vpnConfigurationModel.serverAddress    = model.serverAddress;
    self.vpnConfigurationModel.serverPort       = model.serverPort;
    self.vpnConfigurationModel.mtu              = model.mtu;
    self.vpnConfigurationModel.ip               = model.ip;
    self.vpnConfigurationModel.subnet           = model.subnet;
    self.vpnConfigurationModel.dns              = model.dns;
    self.vpnConfigurationModel.tunnelBundleId   = model.tunnelBundleId;
    [self applyVpnConfiguration];
}

- (BOOL)startVPN {
    if (self.vpnManager.connection.status == NEVPNStatusDisconnected) {
        NSError *error;
        [self.vpnManager.connection startVPNTunnelAndReturnError:&error];
        
        if (error != 0) {
            const char *errorInfo = [NSString stringWithFormat:@"%@",error].UTF8String;
           
        }else {
            
            return YES;
        }
    }else {
      
    }
    
    return NO;
}
 
- (BOOL)stopVPN {
    if (self.vpnManager.connection.status == NEVPNStatusConnected) {
        [self.vpnManager.connection stopVPNTunnel];
      
        return YES;
    }else  if (self.vpnManager.connection.status == NEVPNStatusConnecting) {
        [self.vpnManager.connection stopVPNTunnel];
    
    }else {

    }
    
    return NO;
}

#pragma mark - Main Func Private
- (void)applyVpnConfiguration {
    [NETunnelProviderManager loadAllFromPreferencesWithCompletionHandler:^(NSArray<NETunnelProviderManager *> * _Nullable managers, NSError * _Nullable error) {
        if (managers.count > 0) {
            self.vpnManager = managers[0];
            // 设置完成后更新主控制器的按钮状态
            if (self.delegate && [self.delegate respondsToSelector:@selector(loadFromPreferencesComplete)]) {
                [self.delegate loadFromPreferencesComplete];
            }
          
            return;
        }else {
        }
        
        [self.vpnManager loadFromPreferencesWithCompletionHandler:^(NSError * _Nullable error) {
            if (error != 0) {
                const char *errorInfo = [NSString stringWithFormat:@"%@",error].UTF8String;
            
                return;
            }
            
            NETunnelProviderProtocol *protocol = [[NETunnelProviderProtocol alloc] init];
            protocol.providerBundleIdentifier  = self.vpnConfigurationModel.tunnelBundleId;
            
            NSMutableDictionary *configInfo = [NSMutableDictionary dictionary];
            [configInfo safeSetObject:self.vpnConfigurationModel.serverPort       forKey:@"port"];
            [configInfo safeSetObject:self.vpnConfigurationModel.serverAddress    forKey:@"server"];
            [configInfo safeSetObject:self.vpnConfigurationModel.ip               forKey:@"ip"];
            [configInfo safeSetObject:self.vpnConfigurationModel.subnet           forKey:@"subnet"];
            [configInfo safeSetObject:self.vpnConfigurationModel.mtu              forKey:@"mtu"];
            [configInfo safeSetObject:self.vpnConfigurationModel.dns              forKey:@"dns"];
            
            protocol.providerConfiguration        = configInfo;
            protocol.serverAddress                = self.vpnConfigurationModel.serverAddress;
            self.vpnManager.protocolConfiguration = protocol;
            self.vpnManager.localizedDescription  = @"NEPacketTunnelVPNDemoConfig";
            
            [self.vpnManager setEnabled:YES];
            [self.vpnManager saveToPreferencesWithCompletionHandler:^(NSError * _Nullable error) {
                if (error != 0) {
                    const char *errorInfo = [NSString stringWithFormat:@"%@",error].UTF8String;
                 
                }else {
                    [self applyVpnConfiguration];
            
                }

            }];
        }];
    }];
}

@end
