; default grammar added
(set-logic BV)
(synth-fun Imp((k1 Bool)(k2 Bool)(k3 Bool)(r1 Bool)(r2 Bool)(r3 Bool)(r4 Bool))
 Bool
(( NTbool Bool))
((NTbool Bool(k1 k2 k3 r1 r2 r3 r4 (and NTbool NTbool)(or NTbool NTbool)(not NTbool)))
)
)

(declare-var k1 Bool)
(declare-var k2 Bool)
(declare-var k3 Bool)
(declare-var r1 Bool)
(declare-var r2 Bool)
(declare-var r3 Bool)
(declare-var r4 Bool)
( constraint  (= (xor (xor (xor (xor (xor (and r3 (not r2)) (and (not (xor r2 k2)) (xor r3 k3))) (xor (and r2 (xor k3 r3)) (and r3 (xor r2 k2)))) r4) (xor r1 k1)) (xor r1 false)) (Imp k1 k2 k3 r1 r2 r3 r4 )) ) 
(check-synth)
