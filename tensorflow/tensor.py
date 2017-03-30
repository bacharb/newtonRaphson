import tensorflow as tf
import numpy      as np
import pandas     as pd
import pandas_datareader.data as web
import quandl     as ql
import datetime

pd.set_option('expand_frame_repr', False)

days = datetime.timedelta(days=50)
end = datetime.date.today()  
start = end - days


tickers = ["^gspc", "^nya", "^dji", "^n225","^ftse","^hsi","^aord","^gdaxi"]
indices = tickers
 

sites  =  ['yahoo','google','quandl','def']

data =     web.DataReader(indices,  'yahoo', start, end)

sliceKey = 'Close'

closeData = data[sliceKey].fillna(method='ffill')


closeData = closeData / closeData.max()   # transformation
print (closeData)

closeData = np.log(closeData/closeData.shift()) # log return 

