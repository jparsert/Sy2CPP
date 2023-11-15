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
( constraint  (= (xor (xor (xor (xor (or r2 r3) (xor (xor r3 k3) (xor r1 k1))) (and (or (xor r2 r1) (xor (xor r3 k3) false)) (or (xor r1 (xor r2 k2)) (xor (xor r3 k3) true)))) r4) (and (and r3 (xor r2 k2)) (not false))) (Imp k1 k2 k3 r1 r2 r3 r4 )) ) 
(check-synth)
