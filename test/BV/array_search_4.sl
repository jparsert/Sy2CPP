; default grammar added
(set-logic BV)
(synth-fun findIdx((y1 (_ BitVec 32))(y2 (_ BitVec 32))(y3 (_ BitVec 32))(y4 (_ BitVec 32))(k1 (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(y1 y2 y3 y4 k1 (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var k (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
(declare-var x2 (_ BitVec 32))
(declare-var x3 (_ BitVec 32))
(declare-var x4 (_ BitVec 32))
( constraint  (=> (and (bvult x1 x2) (and (bvult x2 x3) (bvult x3 x4))) (=> (bvult k x1) (= (findIdx x1 x2 x3 x4 k ) (_ bv0 32)))) ) 
( constraint  (=> (and (bvult x1 x2) (and (bvult x2 x3) (bvult x3 x4))) (=> (bvugt k x4) (= (findIdx x1 x2 x3 x4 k ) (_ bv4 32)))) ) 
( constraint  (=> (and (bvult x1 x2) (and (bvult x2 x3) (bvult x3 x4))) (=> (and (bvugt k x1) (bvult k x2)) (= (findIdx x1 x2 x3 x4 k ) (_ bv1 32)))) ) 
( constraint  (=> (and (bvult x1 x2) (and (bvult x2 x3) (bvult x3 x4))) (=> (and (bvugt k x2) (bvult k x3)) (= (findIdx x1 x2 x3 x4 k ) (_ bv2 32)))) ) 
( constraint  (=> (and (bvult x1 x2) (and (bvult x2 x3) (bvult x3 x4))) (=> (and (bvugt k x3) (bvult k x4)) (= (findIdx x1 x2 x3 x4 k ) (_ bv3 32)))) ) 
(check-synth)
