function plot_vectors_3D(start_points,vector)
  quiver3(start_points(1,:),start_points(2,:),start_points(3,:),vector(1,:),vector(2,:),vector(3,:),0)
  axis equal
end

