; default grammar added
(set-logic BV)
(synth-fun skel((LN8 Bool)(k4 Bool)(LN75 Bool)(LN88 Bool)(LN92 Bool))
 Bool
(( NTbool Bool))
((NTbool Bool(LN8 k4 LN75 LN88 LN92 (and NTbool NTbool)(or NTbool NTbool)(not NTbool)))
)
)

(declare-var LN75 Bool)
(declare-var LN8 Bool)
(declare-var LN88 Bool)
(declare-var LN92 Bool)
(declare-var k4 Bool)
( constraint  (= (not (not (not (not (xor LN92 (xor (xor LN75 (and LN8 k4)) LN88)))))) (skel LN8 k4 LN75 LN88 LN92 )) ) 
(check-synth)
