import torch
import torch.nn as nn
import torch.nn.functional as F

def image2emb_naive(image,patch_size, weight):
    # images shape: batchsize*channel*h*w
    # torch.nn.functional.unfold，每次拿出卷积的小区域
    patch = F.unfold(image,kernel_size=patch_size,stride=patch_size).transpose(-1,-2)
    # (1,4.48)batchsize=1,4块，48=patch_depth
    print(patch.shape)
    patch_embedding = patch @ weight
    return patch_embedding

def image2emb_conv(image,kernel,stride):
    conv_output = F.conv2d(image,kernel,stride=stride)
    # bs*oc*oh*ow
    bs,oc,oh,ow = conv_output.shape
    patch_embedding = conv_output.reshape((bs,oc,oh*ow)).transpose(-1,-2)
    return patch_embedding

# test code
batch_size,input_channel, image_h,image_w = 1,3,8,8
patch_size = 4
model_dim = 8 #输出通道数目，patch——depth是卷积核面积乘以输出通道数
patch_depth = patch_size*patch_size*input_channel
image = torch.randn(batch_size,input_channel, image_h,image_w)
# patch大小映射到model dim大小
weight = torch.randn(patch_depth,model_dim)
print(weight.shape)
patch_embeding_naive = image2emb_naive(image,patch_size,weight)
print(patch_embeding_naive)

kernel = weight.transpose(0,1).reshape((-1,input_channel,patch_size,patch_size))
patch_embeding_conv = image2emb_conv(image,kernel,patch_size)
print(patch_embeding_conv)


# CLS token embedding
cls_token_embedding = torch.randn(batch_size,1,model_dim,requires_grad=True)
token_embeding = torch.cat([cls_token_embedding,patch_embeding_conv],dim=1)

max_num_token = 16
# position embedding
position_embedding_table = torch.randn(max_num_token,model_dim,requires_grad=True)
seq_len = token_embeding.shape[1]
position_embedding = torch.tile(position_embedding_table[:seq_len],[token_embeding.shape[0],1,1])

token_embeding += position_embedding

# pass embedding to transfomer encoder
encoder_layer = nn.TransformerEncoderLayer(d_model = model_dim,nhead=8)
transformer_encoder = nn.TransformerEncoder(encoder_layer,num_layers=6)
encoder_output = transformer_encoder(token_embeding)

# classify
cls_token_output = encoder_output[:,0,:]
num_classes = 10
linear_layer = nn.Linear(model_dim,num_classes)
logists = linear_layer(cls_token_output)
label = torch.randint(10,(batch_size,))
loss_fn = nn.CrossEntropyLoss
loss = loss_fn(logists,label)
print(loss)
