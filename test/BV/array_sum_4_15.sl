; default grammar added
(set-logic BV)
(synth-fun findSum((y1 (_ BitVec 32))(y2 (_ BitVec 32))(y3 (_ BitVec 32))(y4 (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(y1 y2 y3 y4 (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x1 (_ BitVec 32))
(declare-var x2 (_ BitVec 32))
(declare-var x3 (_ BitVec 32))
(declare-var x4 (_ BitVec 32))
( constraint  (=> (bvugt (bvadd x1 x2) (_ bv15 32)) (= (findSum x1 x2 x3 x4 ) (bvadd x1 x2))) ) 
( constraint  (=> (and (bvule (bvadd x1 x2) (_ bv15 32)) (bvugt (bvadd x2 x3) (_ bv15 32))) (= (findSum x1 x2 x3 x4 ) (bvadd x2 x3))) ) 
( constraint  (=> (and (and (bvule (bvadd x1 x2) (_ bv15 32)) (bvule (bvadd x2 x3) (_ bv15 32))) (bvugt (bvadd x3 x4) (_ bv15 32))) (= (findSum x1 x2 x3 x4 ) (bvadd x3 x4))) ) 
( constraint  (=> (and (bvule (bvadd x1 x2) (_ bv15 32)) (and (bvule (bvadd x2 x3) (_ bv15 32)) (bvule (bvadd x3 x4) (_ bv15 32)))) (= (findSum x1 x2 x3 x4 ) (_ bv0 32))) ) 
(check-synth)
