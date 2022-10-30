from Crypto.Util.number import bytes_to_long, long_to_bytes

def rsa(m: int, e: int, n: int) -> int:
    return pow(m, e, n)

if __name__ == '__main__':
    n: int = 30474666726037395738317575209965047067855111931159746047114322188511977725239650286292764853420146350399639782033690590052065651320031985479179079492753204505948595714791619439757157685104192079718865307436984310453471758750888086106079335726820357647379310066224403365353411658184030286207767733348938563093435009721504234008994095594468390586236890095117186933254765337404910500901816641856681063070809306199958454104026999925053170716077785517601047280139938813444865354392507295876604919876813362253592013729208623148913532867967574548741913354821332902511640338490471392963085983627917592373751005057080517830098829143231406808888542823807378463027654812374495111729041867190195983466532744403524397310466564228226090715455523025844085510640134879729563342759942890084531548496796060853369030886129330024950094948533649734764307691151145157611756878293615526135400969360529213013502977830159394892925294976363883543267054415992250055031968417627393078577860648966907436005967631813236884437209854860201954040735852801030133099384726287142973867120324051200007535563671956433461619414199181815220843693378699231897369567098579113634248327325525860638823419555977466704404395874009082842663373116120445179810945730951090478195164809691606740628429610196039762120625868036369899736437132071291114892016484757834339463738392619830391287883882291273756124149108204381384760534794235180619629028460990746108172915940011982772721969961684323595891388320289897795758002888037702932951221593269501223967434808860297206866156781693571010711504942688822728840160260327481800682928486833507524613598501802182118101443232737206728071019415796567026709815035331734811407831692463867881914464453079016447003790465438014244793019427477882713095665916036048375977121907853983027630419940568401550819381841262287748249199696474428645343172584150140633213639822497
    e: int = 301440962207102637518790636996292519941367417773401736670494507591004735922026140680458330920740056693828220641870940068238728396127403631329751655313984803396541606932099541043556282424625588466517946399887369652282163717968052530476164791499546957917891708977137967101749311199936786786563550264523828082505847144580337685925644679943239184924611398912330312784415684891265016837191274148352016215741696820680924199820580157398817964805743138765029322776928359071204910704524189799764818649894245578110247977447856571386788952669047802070167004618339225011381618149208350488917205486911936871840436136078742850996055710098549416139582686549112214540599740037905709559156629749890359674725441737676461632133617787667909908184195195402549243750130180609836206506313624262006657396990599903839139310443060530990806761849540064561717892794027094935163578577333983378770252413984362021335920840292406026345326066300386315215240953418621284937257426884587505099536432044975594507010549449137881595842590247538094276901978552366366853229654940943277809199089397255680063401426934295822213426354516021097095864353105357307282455171720855269050949467781996383481391472954825897037660929266120483036899635191501780412798134511516788127393380313795253751818163394653264321589913615763188058391822616127855580306046982866355282351871480020274799977202853876658966813650670084195481538397943090695519467678292687031609085556688191681312407697947953671809733017969548704838864408391840626322887557270332751364043157540991122792913406763960900105652157301772154381901277971270758020420863303530906740602543580559942351343440026220099013213891104784369045476404574201548651724299715899515839365237582732285071646453882490230178154869630140537844034835471818045094934833083630334472796770501806296002236475570338345632476099298123707185899400698470036802539294919
    d = 0

    texto_cifrado_int: int = 24200645846607967357560090303354606319451303165660956997452126002612938596413243825053362508058841543413189736542138213469945451030753619498115262635400500433543896753888918777938028859485375880254746653331838585821649847782470010113463591937056058298750208836642816927044200152758573190968314757807618800954785796126007506297841970883332322029150705925486099822843343046569331742668889801322667539577942726551607137748732338786504258229651009147339072104009328937418971503756842898532266843515864579012154100334788705043042845782833021832307000896089356266508603055240281371493071110614112525457516349987532137424101145318027808590664680327926329313551233651012924875713023759770385466750424739001074758618348007776825080766081588416363885840357417610549650760789017713798481030717792520275771266739443912154421133139478736778247630776484092978258522777273626170996825564663327434378142177106791714096448459496869030298731124313631032923569158029778311192872918042970521594919593336208913566967568411606932013723041184293975212024115198732827715473690029379427934517145959715741726970185844943594112759739476217107016320197384221598987250617116169933300799778119586554876158277727365431477414434132215170369569956122302354737084357572061980347023295845027771372644503068033101593881350712770383133364269331384665981340052538448830871822290728178747686684681776507494102390729957487410284362753748409181040276285293305537564776062660160029799200381537326615577907744446370453874767547596539792442261507105255977798835391647992002058558302259127594008069018018347027173737457289558798157479322919546175347584563392675064509750616084883063324735740595466636882441590214614895900775107393243573646641340065640962300474130916488394495369458420440842781824682128497817077103183030862453829034264751868404655801733272059483349561149017655426157018486027803
    print(f'{texto_cifrado_int=}')

    texto_decriptografado: str = long_to_bytes(rsa(texto_cifrado_int, d, n)).decode('UTF-8')
    print(f'{texto_decriptografado=}')
    print(f'EITS{{{texto_decriptografado}}}')
